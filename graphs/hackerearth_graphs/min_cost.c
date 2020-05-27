#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define ll long long
#define MAX 50005
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
Add (ll H[], ll A[], ll B[], ll X, ll *n)
{

  H[*n] = X;
  A[*n] = *n;
  B[A[*n]] = *n;
  *n = *n + 1;

  Bottomupheapify (H, A, B, *n - 1);
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
BuildHeap (ll H[], ll A[], ll B[], ll n)
{

  ll i = n / 2;
  while (i > -1)
    {
      Topdownheapify (H, A, B, i--, n);

    }

}

void
DecreaseKey (ll H[], ll A[], ll B[], ll i, ll X)
{

  H[i] = X;

  Bottomupheapify (H, A, B, i);


}

void
Dijkstra (struct List *list[], ll s, ll n)
{
  ll A[MAX], B[MAX];
  struct List *node;
  ll H[MAX];
  ll i, u, v, m = n;
  bool V[n];
  for (i = 0; i < n; ++i)
    {
      H[i] = INT_MAX;
      A[i] = i;
      B[i] = i;
      V[i] = false;
    }

  H[0] = 0;
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
	    }
	  node = node->next;
	}
    }
    printf("%lld\n",H[B[n-1]]);

}
void main()
{
    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        ll n,i;
        scanf("%lld",&n);
        ll p[n];
        struct List*list[n];
        for(i=0;i<n;i++) 
        {
            scanf("%lld",&p[i]);
            list[i]=NULL;  
        }
        for(i=0;i<n;i++)
        {
            if(i+1<n)
            list[i]=newedge(list[i],i+1,1);
            if(i-1>-1)
            list[i]=newedge(list[i],i-1,1);
            list[i]=newedge(list[i],p[i]-1,0);
        }
        Dijkstra(list,0,n);
    }
}