#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<limits.h>
#define ll long long 
#define MAX_NUMBER 100000
struct List
{
  ll int i;
  ll int w;
  struct List *next;
};
struct List *Mst[MAX_NUMBER];
bool Visited[MAX_NUMBER]={false};
ll int res[1010][1010];
struct List *
newedge (struct List *node, ll int i, ll int w)
{
  struct List *temp = (struct List *) malloc (sizeof (struct List));
  temp->i = i;
  temp->w = w;
  temp->next = node;
  return temp;
}
 
void DFS(ll int s,ll int org,ll int tot)
{
    res[org][s]=tot;
    Visited[s]=true;
    struct List*temp=Mst[s];
    while (temp)
    {
        if(!Visited[temp->i])
        {
            DFS(temp->i,org,tot+(temp->w));
        }
        temp=temp->next;
    }
    
}
 
void
Bottomupheapify (ll int H[], ll int A[], ll int B[], ll int i)
{
  ll int p = (i - 1) / 2, t;
  ll int temp;
 
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
Topdownheapify (ll int H[], ll int A[], ll int B[], ll int i, ll int n)
{
  ll int c, t;
  ll int temp;
 
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
Add (ll int H[], ll int A[], ll int B[], ll int X, ll int *n)
{
 
  H[*n] = X;
  A[*n] = *n;
  B[A[*n]] = *n;
  *n = *n + 1;
 
  Bottomupheapify (H, A, B, *n - 1);
}
 
void
DeleteMin (ll int H[], ll int A[], ll int B[], ll int *n)
{
  ll int t;
  ll int t1;
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
DecreaseKey (ll int H[], ll int A[], ll int B[], ll int i, ll int X)
{
 
  H[i] = X;
 
  Bottomupheapify (H, A, B, i);
 
 
}
 
void
PrimsMin (struct List *list[], ll int s, ll int n)
{
  ll int A[MAX_NUMBER], B[MAX_NUMBER];
  struct List *node;
  ll int H[MAX_NUMBER];
  ll int i, u, v, m = n;
  bool V[n];
  ll int Phi[n];
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
	  if (!V[v] && H[B[v]] > node->w)
	    {
	      DecreaseKey (H, A, B, B[v], node->w);
	      Phi[v] = u;
	    }
	  node = node->next;
	}
    }
 
  for(i=0;i<n;i++) Mst[i]=NULL;
  for(i=0;i<n;i++)
  {
      Mst[i]=newedge(Mst[i],Phi[i],H[B[i]]);
      Mst[Phi[i]]=newedge(Mst[Phi[i]],i,H[B[i]]);
  }
  
}
int main()
{
    ll int t,count=1;
    scanf("%lld",&t);
    while(t--)
    {
        ll int N,M,P;
        scanf("%lld %lld %lld",&N,&P,&M);
        struct List*list[N];
        for(ll int i=0;i<N;i++) list[i]=NULL;
        while(P--)
        {
            ll int u,v,d;
            scanf("%lld %lld %lld",&u,&v,&d);
            list[u-1]=newedge(list[u-1],v-1,d);
            list[v-1]=newedge(list[v-1],u-1,d);
        }
        PrimsMin(list,0,N);
        for(ll int i=0;i<N;i++)
        {
            memset(Visited,false,N);
            DFS(i,i,0);
        }
        printf("Case: %lld\n",count++);
        while(M--)
        {
            ll int u,v;
            scanf("%lld %lld",&u,&v);
            printf("%lld\n",res[u-1][v-1]);
        }
    }
    return 0;
}