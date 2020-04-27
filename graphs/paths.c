#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include<limits.h>

struct List
{
  int i;
  float w;
  struct List *next;
};
struct EdgeList
{
  int i, j;
  float w;
  struct EdgeList *next;
};

struct EdgeList *
newedgelist (struct EdgeList *node, int i, int j, float w)
{
  struct EdgeList *temp =
    (struct EdgeList *) malloc (sizeof (struct EdgeList));
  temp->i = i;
  temp->j = j;
  temp->w = w;
  temp->next = node;
  return temp;
}

struct List *
newedge (struct List *node, int i, float w)
{
  struct List *temp = (struct List *) malloc (sizeof (struct List));
  temp->i = i;
  temp->w = w;
  temp->next = node;
  return temp;
}

void
BellmanFord (struct EdgeList *elist, float SD[], int s, int n)
{
  struct EdgeList *temp;
  int i;

  for (i = 0; i < n; ++i)
    SD[i] = INT_MAX;
  SD[s] = 0;

  for (i = 0; i < n; ++i)
    {
      temp = elist;
      while (temp)
	{
	  if (SD[temp->j] > SD[temp->i] + temp->w)
	    SD[temp->j] = SD[temp->i] + temp->w;

	  temp = temp->next;
	}

    }
}

void
FloydWarshall (float A[][1000], float D[][1000], int n)
{
  int i, j, k;
  for (i = 0; i < n; ++i)
    for (j = 0; j < n; ++j)
      D[i][j] = A[i][j];
  for (i = 0; i < n; ++i)
    D[i][i] = 0;
  for (k = 0; k < n; ++k)
    for (i = 0; i < n; ++i)
      for (j = 0; j < n; ++j)
	if (D[i][j] > D[i][k] + D[k][j])
	  D[i][j] = D[i][k] + D[k][j];
}

void
main ()
{
  int i, n = 200, l, r, m = 0, j, k;
  float A[1000][1000], D[1000][1000], SD[1000];
  struct List *list[n], *temp;
  struct EdgeList *elist = NULL, *etemp;

  for (i = 0; i < n; ++i)
    for (j = 0; j < n; ++j)
      A[i][j] = INT_MAX;
  for (i = 0; i < n; ++i)
    list[i] = NULL;
  for (i = 0; i < n; ++i)
    for (k = 0; k < n / 10; ++k)
      {
	j = rand () % n;

	A[i][j] = (i + j) * 2.1234;
	list[i] = newedge (list[i], j, (i + j) * 2.1234);
	elist = newedgelist (elist, i, j, (i + j) * 2.1234);
	++m;

      }

  printf ("%d\n", m);

  FloydWarshall (A, D, n);

  for (i = 0; i < n; ++i)
    {
      BellmanFord (elist, SD, i, n);

      for (j = 0; j < n; ++j)

	if (abs (SD[j] - D[i][j]) > 0.1)
	  printf ("%f %f \n", SD[j], D[i][j]);
    }

}

