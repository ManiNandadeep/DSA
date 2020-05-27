#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#include <string.h>
bool V[100000]={false};
struct List
{
  int i;
  int w;
  struct List *next;
};

struct List *
newedge (struct List *node, int i, int w)
{
  struct List *temp = (struct List *) malloc (sizeof (struct List));
  temp->i = i;
  temp->w = w;
  temp->next = node;
  return temp;
}

int min(int a,int b)
{
    if(a<b) return a;
    return b;
} 

void
Bottomupheapify (int H[], int A[], int B[], int i)
{
  int p = (i - 1) / 2, t;
  int temp;

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
Topdownheapify (int H[], int A[], int B[], int i, int n)
{
  int c, t;
  int temp;

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
Add (int H[], int A[], int B[], int X, int *n)
{

  H[*n] = X;
  A[*n] = *n;
  B[A[*n]] = *n;
  *n = *n + 1;

  Bottomupheapify (H, A, B, *n - 1);
}

void
DeleteMin (int H[], int A[], int B[], int *n)
{
  int t;
  int t1;
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
BuildHeap (int H[], int A[], int B[], int n)
{

  int i = n / 2;
  while (i > -1)
    {
      Topdownheapify (H, A, B, i--, n);

    }

}

void
DecreaseKey (int H[], int A[], int B[], int i, int X)
{

  H[i] = X;

  Bottomupheapify (H, A, B, i);


}

void
Dijkstra (struct List *list[], int s, int n,int x,int dist[])
{
  int A[100000], B[100000];
  struct List *node;
  int H[100000];
  int i, u, v, m = n;
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
    for(int i=0;i<n;i++)
    {
       dist[i]=H[B[i]];
    }
}
int main()
{
    int n,m,k,x,a,b;
    scanf("%d %d %d %d",&n,&m,&k,&x);
    bool available[n];
    memset(available,false,n);
    for(int i=0;i<k;i++)
    {
        int city;
        scanf("%d",&city);
        available[city-1]=true;
    } 
    struct List*list[n];
    for(int i=0;i<n;i++) list[i]=NULL;
    for(int i=0;i<m;i++)
    {
        int u,v,d;
        scanf("%d %d %d",&u,&v,&d);
        list[u-1]=newedge(list[u-1],v-1,d);
        list[v-1]=newedge(list[v-1],u-1,d);
    }
    scanf("%d %d",&a,&b);
    int cls_a[n];
    Dijkstra(list,a-1,n,x,cls_a);
    int cls_b[n];
    Dijkstra(list,b-1,n,x,cls_b);
    if(cls_a[b-1]==INT_MAX||cls_b[a-1]==INT_MAX)
    {
        printf("-1\n");
        return 0;
    }
    int choices[100000],size=0;
    for(int i=0;i<n;i++)
    {
        if(V[i]&&available[i]&&cls_b[i]<=x)
        {
            choices[size++]=i;
        }
    }
    int ans=INT_MAX;
    for(int i=0;i<size;i++)
    {
        ans=min(ans,cls_a[choices[i]]+cls_b[choices[i]]);
    }
    printf("%d",ans);
    return 0;
}