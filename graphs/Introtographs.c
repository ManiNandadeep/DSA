#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

struct List
{
  int i;
  struct List *next;
};
struct EdgeList
{
  int i, j;
  struct EdgeList *next;
};

struct EdgeList *
newedgelist (struct EdgeList *node, int i, int j)
{
  struct EdgeList *temp =
    (struct EdgeList *) malloc (sizeof (struct EdgeList));
  temp->i = i;
  temp->j = j;
  temp->next = node;
  return temp;
}

struct List *
newedge (struct List *node, int i)
{
  struct List *temp = (struct List *) malloc (sizeof (struct List));
  temp->i = i;
  temp->next = node;
  return temp;
}

void
main ()
{
  int i, n = 1000, l, r, m = 0, j, k;
  bool A[1000][1000];
  struct List *list[n], *temp;
  struct EdgeList *elist = NULL, *etemp;


  for (i = 0; i < n; ++i)
    list[i] = NULL;
  for (i = 0; i < n; ++i)
    for (k = 0; k < n / 10; ++k)
      {
	j = rand () % n;
	if (!A[i][j])
	  {
	    A[i][j] = true;
	    list[i] = newedge (list[i], j);
	    elist = newedgelist (elist, i, j);
	    ++m;
	  }
      }

  printf ("%d\n", m);

/*
  for (i = 0; i < n; ++i)
    {
      temp = list[i];
      while (temp)
	{
	  printf ("%d %d ", i, temp->i);
	  temp = temp->next;

	}

      printf ("\n..\n");
    }

  for (i = 0; i < n; ++i)
    {

      for (j = 0; j < n; ++j)
	{

	  if (A[i][j])
	    printf ("%d, %d  ", i, j);
	}
      printf ("\n");
    }

  etemp = elist;
  while (etemp)
    {
      printf ("%d %d ", etemp->i, etemp->j);
      etemp = etemp->next;
    }*/
}
