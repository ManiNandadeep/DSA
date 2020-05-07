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

int
connected (struct List *list[], int n)
{
  bool V[n];
  int Phi[n], i, c = 0, C[n], s;

  for (i = 0; i < n; ++i)
    {
      Phi[i] = -2;
      V[i] = false;
      C[i] = 0;
    }
  for (i = 0; i < n; ++i)
    {
      if (C[i] == 0)
	{

	  c++;
	  s = i;
	  struct List *head = (struct List *) malloc (sizeof (struct List));
	  head->i = s;
	  head->next = NULL;
	  V[s] = true;
	  Phi[s] = -1;
	  C[s] = c;
	  struct List *tail = head, *temp;
	  while (head)
	    {
	      temp = list[head->i];
	      while (temp)
		{
		  if (!V[temp->i])
		    {
		      tail->next =
			(struct List *) malloc (sizeof (struct List));
		      tail = tail->next;
		      tail->i = temp->i;
		      tail->next = NULL;
		      V[temp->i] = true;
		      Phi[temp->i] = head->i;
		      C[temp->i] = c;
		    }
		  temp = temp->next;
		}
	      head = head->next;
	    }
	}
    }

  printf (" \n The numbe of Connected Componests %d is\n", c);

  for (i = 0; i < n; ++i)
    printf ("(%d,%d)", i, C[i]);
  return c;
}

int
BFS (struct List *list[], int s, int n)
{

  bool V[n];
  int Phi[n], i, L[n];

  for (i = 0; i < n; ++i)
    {
      Phi[i] = -2;
      V[i] = false;
    }
  struct List *head = (struct List *) malloc (sizeof (struct List));
  head->i = s;
  head->next = NULL;
  V[s] = true;
  L[s] = 0;
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
	      L[temp->i] = L[head->i] + 1;

	    }
	  temp = temp->next;
	}
      head = head->next;
    }
  /* printf (" \n BFS from %d is\n", s);

     for (i = 0; i < n; ++i)
     printf ("(%d,%d,%d)", Phi[i], i,L[i]);
   */
  for (i = 0; i < n; ++i)
    {
      temp = list[i];
      while (temp)
	{
	  if (L[i] % 2 == L[temp->i] % 2)
	    {
	      //printf ("\n The graph is not a bipartite graph \n");
	      i = n + 1;
	      temp = NULL;
	    }
	  else
	    temp = temp->next;
	}
    }
  // if(i==n)
  //printf ("\n The graph is a bipartite graph \n");

  int max = L[0];
  for (i = 1; i < n; ++i)
    if (L[i] > max)
      max = L[i];

  return max;

}

int
Diameter (struct List *list[], int n)
{
  int d = 0, i, max;
  for (i = 0; i < n; ++i)
    {
      max = BFS (list, i, n);
      if (max > d)
	d = max;
    }
  return d;

}


void
main ()
{
  int A[100000], C[100000], n = 6000, m, i, j, k;
  float H[100000];
  bool AM[1000][1000];


  struct List *list[n], *temp, *listu[n];

  for (i = 0; i < n; ++i)
    {
      list[i] = NULL;
      listu[i];
    }

  m = 0;
  for (i = 0; i < n; ++i)
    {
      j = rand () % n;
      while (j < n)
	{
	  if (i == j)
	    j++;
	  listu[i] = newedge (listu[i], j);
	  list[i] = newedge (list[i], j);
	  list[j] = newedge (list[j], i);

	  ++m;
	  // printf ("(%d %d)", i, j);
	  j += rand () % n + 1;
	}

      //if(i%5==0) i++;
    }
  printf ("\nThe number of edges in the graph is %d\n", m);
//  BFS (list, 4, n);
//connected(list, n);

  printf ("\nThe Diameter of the graph is %d\n", Diameter (list, n));
}
