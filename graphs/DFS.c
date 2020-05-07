#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct List
{
  int i;
  struct List *next;
};



struct List *
newedge (struct List *node, int i)
{
  struct List *temp = (struct List *) malloc (sizeof (struct List));
  temp->i = i;
  temp->next = node;
  return temp;
}

struct Listw
{
  int i;
  float w;
  struct Listw *next;
};



struct Listw *
newedgew (struct Listw *node, int i, float w)
{
  struct Listw *temp = (struct Listw *) malloc (sizeof (struct Listw));
  temp->i = i;
  temp->w = w;
  temp->next = node;
  return temp;
}

void
BFS (struct List *list[], int s, int n)
{
  bool V[n];
  int Phi[n], i;

  for (i = 0; i < n; ++i)
    {
      Phi[i] = -2;
      V[i] = false;
    }
  struct List *head = (struct List *) malloc (sizeof (struct List));
  head->i = s;
  head->next = NULL;
  V[s] = true;
  Phi[s] = -1;
  struct List *tail = head, *temp;
  while (head)
    {
      temp = list[head->i];
      while (temp)
	{
	  if (!V[temp->i])
	    {
	      tail->next = (struct List *) malloc (sizeof (struct List));
	      tail = tail->next;
	      tail->i = temp->i;
	      tail->next = NULL;
	      V[temp->i] = true;
	      Phi[temp->i] = head->i;
	    }
	  temp = temp->next;
	}
      head = head->next;
    }
  printf (" \n BFS from %d is\n", s);

  for (i = 0; i < n; ++i)
    printf ("(%d,%d)", Phi[i], i);

}

void
iDFS (struct List *list[], int s, int n)
{
  bool V[n];
  int Phi[n], i, d[n], f[n], c = 1;
  for (i = 0; i < n; ++i)
    {
      Phi[i] = -2;
      V[i] = false;
      f[i] = 0;
    }

  struct List *head = (struct List *) malloc (sizeof (struct List));
  head->i = s;
  head->next = NULL;
  Phi[s] = -1;
  struct List *temp, *t1, *h1;
  while (head)
    {
      if (!V[head->i])
	{
	  V[head->i] = true;
	  temp = list[head->i];
	  d[head->i] = c++;
	  if (temp)
	    {
	      h1 = head;
	      // head = head->next;
	      while (temp)
		{
		  if (!V[temp->i])
		    {
		      head = newedge (head, temp->i);

		      Phi[temp->i] = h1->i;

		    }


		  temp = temp->next;
		}


	    }
	  else
	    {
	      if (!f[head->i])
		f[head->i] = c++;
	      head = head->next;
	    }
	}
      else
	{
	  if (!f[head->i])
	    f[head->i] = c++;
	  head = head->next;
	}

    }
  printf (" \n DFS Tree from %d is\n", s);


  for (i = 0; i < n; ++i)
    printf ("(%d,%d,%d,%d)", Phi[i], i, d[i], f[i]);

}

void
DFSvist (struct List *list[], int u, bool V[], int Phi[], int d[], int f[],
	 int n, int *c)
{
  *c = *c + 1;
  V[u] = true;
  d[u] = *c;

  struct List *temp = list[u];
  while (temp)
    {
      if (!V[temp->i])
	{
	  Phi[temp->i] = u;
	  DFSvist (list, temp->i, V, Phi, d, f, n, c);
	}
      temp = temp->next;
    }
  *c = *c + 1;
  f[u] = *c;
}

void
DFS (struct List *list[], int s, int n)
{
  bool V[n];
  int Phi[n], i, d[n], f[n], c;
  c = 0;
  for (i = 0; i < n; ++i)
    {
      Phi[i] = -2;
      V[i] = false;
    }
  Phi[s] = -1;
  c = 0;
  DFSvist (list, s, V, Phi, d, f, n, &c);
  for (i = 0; i < n; ++i)
    printf ("(%d %d %d %d) ", i, Phi[i], d[i], f[i]);

}

void
DFSvisttopo (struct List *list[], int u, bool V[], struct List **topo, int n)
{

  V[u] = true;


  struct List *temp = list[u], t1;
  while (temp)
    {
      if (!V[temp->i])
	{
	  DFSvisttopo (list, temp->i, V, &*topo, n);
	}
      temp = temp->next;
    }
  *topo = newedge (*topo, u);
}

struct List *
Topo (struct List *list[], int n)
{
  bool V[n];
  struct List *topo = NULL;
  int i;

  for (i = 0; i < n; ++i)
    V[i] = false;
  for (i = 0; i < n; ++i)
    if (!V[i])
      DFSvisttopo (list, i, V, &topo, n);

  return topo;
}

void
DAGpath (struct Listw *listw[], struct List *list[], int s, int n)
{
  bool V[n];
  struct List *topo = NULL, *t1;
  struct Listw *temp;
  int i;
  float S[n], L[n];
  for (i = 0; i < n; ++i)
    {
      S[i] = INT_MAX;
      L[i] = INT_MIN;
    }

  topo = Topo (list, n);

  while (topo->i != s)
    topo = topo->next;
  S[s] = L[s] = 0;
  while (topo)
    {
      temp = listw[topo->i];
      while (temp)
	{
	  if (S[temp->i] > S[topo->i] + temp->w)
	    S[temp->i] = S[topo->i] + temp->w;
	  if (L[temp->i] < L[topo->i] + temp->w)
	    L[temp->i] = L[topo->i] + temp->w;

	  temp = temp->next;
	}
      topo = topo->next;
    }


}


void
DFSSCC (struct List *list[], int u, int C[], int c, int n)
{

  C[u] = c;


  struct List *temp = list[u];
  while (temp)
    {
      if (C[temp->i] == 0)
	{
	  DFSSCC (list, temp->i, C, c, n);
	}
      temp = temp->next;
    }

}

int
SCC (struct List *list[], int n)
{
  bool V[n];
  struct List *topo = NULL, *listT[n], *temp;
  int i, C[n], c = 0;

  for (i = 0; i < n; ++i)
    {
      V[i] = false;
      listT[i] = NULL;
      C[i] = 0;
    }
  for (i = 0; i < n; ++i)
    if (!V[i])
      DFSvisttopo (list, i, V, &topo, n);
  for (i = 0; i < n; ++i)
    {
      temp = list[i];
      while (temp)
	{
	  listT[temp->i] = newedge (listT[temp->i], i);
	  temp = temp->next;
	}


    }

  while (topo)
    {

      if (C[topo->i] == 0)
	{
	  c++;
	  DFSSCC (listT, topo->i, C, c, n);
	}
      topo = topo->next;
    }

//for (i = 0; i < n; ++i)
//printf("(%d %d)",i,C[i]);

  return c;
}


void
main ()
{
  int A[100000], B[100000], n = 96000, m, i, j, k;
  float H[100000];
  bool AM[1000][1000];


  struct List *list[n], *temp, *listd[n];
  struct Listw *wtemp, *list1[n];

  for (i = 0; i < n; ++i)
    {
      list[i] = NULL;
      list1[i] = NULL;
      listd[i];
    }

  m = 0;
  for (i = 0; i < n; ++i)
    {
      j = rand () % n;
      while (j < n)
	{
	  if (i == j)
	    j++;
	  list1[i] = newedgew (list1[i], j, i * j * 2.23 + 1);
	  listd[i] = newedge (listd[i], j);
	  list[i] = newedge (list[i], j);
	  list[j] = newedge (list[j], i);

	  ++m;
	  //  printf ("(%d %d)", i, j);
	  j += rand () % n + 1;
	}
    }
  printf ("\nThe number of edges in the graph is %d\n", m);

  //Topo (listd, n);
  // DAGpath (list1, listd, 0, n);
  printf ("The no of SCC is %d\n", SCC (listd, n));
}
