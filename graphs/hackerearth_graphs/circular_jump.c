#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define ll long long 
struct List
{
  ll i;
  ll w;
  struct List *next;
};



struct List *
newedge (struct List *node, ll i, ll w)
{
  struct List *temp = (struct List *) malloc (sizeof (struct List));
  temp->i = i;
  temp->w = w;
  temp->next = node;
  return temp;
}

void
Bottomupheapify (ll H[], ll A[], ll B[], ll i)
{
  ll p = (i - 1) / 2, t;
  ll temp;

  while (p > -1)
    {
      if (H[i] < H[p])
	{
	  temp = H[i];
	  H[i] = H[p];
	  H[p] = temp;
	  t = A[i];
	  A[i] = A[p];
	  A[p] = t;
	  B[A[i]] = i;
	  B[A[p]] = p;
	  i = p;
	  p = (i - 1) / 2;

	}

      else
	p = -1;
    }

}

void
Topdownheapify (ll H[], ll A[], ll B[], ll i, ll n)
{
  ll c, t;
  ll temp;

  while (2 * i + 2 < n)
    {

      if (H[2 * i + 1] < H[2 * i + 2])
	c = 2 * i + 1;
      else
	c = 2 * i + 2;
      if (H[i] > H[c])
	{
	  temp = H[i];
	  H[i] = H[c];
	  H[c] = temp;
	  t = A[i];
	  A[i] = A[c];
	  A[c] = t;
	  B[A[c]] = c;
	  B[A[i]] = i;
	  i = c;
	}

      else
	i = n;
    }
  c = 2 * i + 1;
  if (c < n & H[i] > H[c])
    {
      temp = H[i];
      H[i] = H[c];
      H[c] = temp;
      t = A[i];
      A[i] = A[c];
      A[c] = t;

      B[A[c]] = c;
      B[A[i]] = i;
      i = c;
    }

}


void
DeleteMin (ll H[], ll A[], ll B[], ll *n)
{
  ll t;
  ll t1;
  *n = *n - 1;
  t = H[0];
  H[0] = H[*n];
  H[*n] = t;
  t1 = A[0];
  A[0] = A[*n];
  A[*n] = t1;
  B[A[0]] = 0;
  B[A[*n]] = *n;
  Topdownheapify (H, A, B, 0, *n);
}


void
DecreaseKey (ll H[], ll A[], ll B[], ll i, ll X)
{

  H[i] = X;

  Bottomupheapify (H, A, B, i);


}



void
Dijkstra (struct List *list[], ll s, ll n,ll des)
{
  ll A[100000], B[100000];
  struct List *node;
  ll H[100000];
  ll i, u, v, m = n;
  bool V[n];
  ll Phi[n];
  for (i = 0; i < n; ++i)
    {
      Phi[i] = -2;
      H[i] = INT_MAX;
      A[i] = i;
      B[i] = i;
      V[i] = false;
    }

  H[0] = 0;
  Phi[s] = -1;
  A[0] = s;
  A[s] = 0;
  B[0] = s;
  B[s] = 0;
  for (i = 0; i < n && H[0] < INT_MAX; ++i)
    {
      u = A[0];
      V[u] = true;
      node = list[u];
      DeleteMin (H, A, B, &m);
      while (node)
	{
	  v = node->i;
	  if (!V[v] && H[B[v]] > H[B[u]] + node->w)
	    {
	      DecreaseKey (H, A, B, B[v], H[B[u]] + node->w);
	      Phi[v] = u;
	    }
	  node = node->next;
	}
    }
    // printf("%lld\n",H[B[des]]);
    if(H[B[des]]==INT_MAX) printf("-1\n");
    else
    {
        printf("%lld\n",H[B[des]]);
    }
}
void main()
{
    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        ll n,x,y;
        scanf("%lld %lld %lld",&n,&x,&y);
        x--;
        y--;
        ll chNum[n];
        for(ll i=0;i<n;i++) scanf("%lld",&chNum[i]),chNum[i]=chNum[i]%n;
        struct List*list[n];
        for(ll i=0;i<n;i++) list[i]=NULL;
        for(ll i=0;i<n;i++)
        {
          list[i]=newedge(list[i],(i+chNum[i])%n,1);
          list[i]=newedge(list[i],(i-chNum[i]+n)%n,1);
        }
        Dijkstra(list,x,n,y);
    }
}
