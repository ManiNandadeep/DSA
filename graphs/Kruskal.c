#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <limits.h>


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
};

struct List *
newedge (struct List *node, int i, float w)
{
  struct List *temp = (struct List *) malloc (sizeof (struct List));
  temp->i = i;
  temp->w = w;
  temp->next = node;
  return temp;
}


struct EdgeList *
newedgelist (int i, int j, float w)
{
  struct EdgeList *temp =
    (struct EdgeList *) malloc (sizeof (struct EdgeList));
  temp->i = i;
  temp->j = j;
  temp->w = w;
  return temp;
}

int
BFS (struct List *list[], int s, int n, bool V[], float M[], int A[], int B[])
{
  int i;

  for (i = 0; i < n; ++i)
    {
      M[i] = INT_MIN;
      V[i] = false;
    }
  struct List *head = (struct List *) malloc (sizeof (struct List));
  head->i = s;

  head->next = NULL;
  V[s] = true;
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
	      if (M[head->i] > temp->w)
		{
		  M[temp->i] = M[head->i];
		  A[temp->i] = A[head->i];
		  B[temp->i] = B[head->i];
		}
	      else
		{
		  M[temp->i] = temp->w;
		  A[temp->i] = temp->i;
		  B[temp->i] = head->i;
		}

	    }
	  temp = temp->next;
	}
      head = head->next;
    }

}

void
Merge (struct EdgeList *elist[], int i, int m, int j)
{
  struct EdgeList *temp[j - i + 1];
  int l = i, r = m + 1, p = 0;
  while (l <= m && r <= j)
    {
      if (elist[l]->w < elist[r]->w)
	temp[p++] = elist[l++];

      else
	temp[p++] = elist[r++];
    }


  while (l <= m)
    temp[p++] = elist[l++];

  while (r <= j)
    temp[p++] = elist[r++];
  l = i;
  p = 0;
  while (l <= j)
    elist[l++] = temp[p++];

}

void
MergeSort (struct EdgeList *elist[], int i, int j)
{
  if (i < j)
    {
      int m = (i + j) / 2;
      MergeSort (elist, i, m);
      MergeSort (elist, m + 1, j);
      Merge (elist, i, m, j);
    }

}

int
find1 (int P[], int i)
{
  if (P[i] == i)
    return i;
  else
    return find1 (P, P[i]);
}

int
find (int P[], int i)
{
  if (P[i] == i)
    return i;
  else
    return P[i] = find (P, P[i]);
}

void
Krushkal (struct EdgeList *elist[], int n, int m)
{

  MergeSort (elist, 0, m - 1);
  int P[n], S[n], h[n], i, j, a, b, MST1[n - 1], MST2[n - 1];
  float mst1 = 0, mst2 = 0;
  for (i = 0; i < n; ++i)
    {
      P[i] = i;
      S[i] = 1;
      h[i] = 0;
    }
  j = 0;
  for (i = 0; i < m; ++i)
    {
      a = find (P, elist[i]->i);
      b = find (P, elist[i]->j);
      if (a != b)
	{
	  MST1[j++] = i;
	  if (S[a] < S[b])
	    {
	      S[b] += S[a];
	      P[a] = b;
	    }
	  else
	    {
	      S[a] += S[b];
	      P[b] = a;
	    }
	}
    }

  j = 0;
  for (i = 0; i < n; ++i)
    P[i] = i;

  for (i = 0; i < m; ++i)
    {
      a = find (P, elist[i]->i);
      b = find (P, elist[i]->j);
      if (a != b)
	{
	  MST2[j++] = i;
	  if (h[a] < h[b])
	    {
	      P[a] = b;
	    }
	  else
	    {
	      P[b] = a;
	      if (h[a] == h[b])
		h[a]++;

	    }
	}
    }

  for (i = 0; i < n - 1; ++i)
    {
      // printf ("%d %d %f \n", elist[MST1[i]]->i, elist[MST1[i]]->j,
      //      elist[MST1[i]]->w);
      // printf ("%d %d %f \n", elist[MST2[i]]->i, elist[MST2[i]]->j,
      //   elist[MST2[i]]->w);
      mst1 += elist[MST1[i]]->w;
      mst2 += elist[MST2[i]]->w;
    }
  printf ("%f %f \n", mst1, mst2);



}

void
Krushkalone (struct EdgeList *elist[], struct List *MST[], int n, int m)
{

  MergeSort (elist, 0, m - 1);
  int C[n], S[n], i, j, a, b;
  float mst = 0;
  struct List *list[n], *temp;
  for (i = 0; i < n; ++i)
    {
      list[i] = NULL;
      MST[i] = NULL;
    }
  for (i = 0; i < n; ++i)
    {
      C[i] = i;
      S[i] = 1;
      list[i] = newedge (list[i], i, 0);
    }
  j = 0;
  for (i = 0; i < m; ++i)
    {
      if (C[elist[i]->i] != C[elist[i]->j])
	{
	  if (S[elist[i]->i] > S[elist[i]->j])
	    {
	      a = elist[i]->i;
	      b = elist[i]->j;
	    }
	  else
	    {
	      b = elist[i]->i;
	      a = elist[i]->j;
	    }
	  MST[a] = newedge (MST[a], b, elist[i]->w);
	  MST[b] = newedge (MST[b], a, elist[i]->w);
	  mst += elist[i]->w;
	  a = C[a];
	  b = C[b];
	  S[a] += S[b];
	  S[b] = 0;
	  while (list[b])
	    {
	      C[list[b]->i] = a;
	      temp = list[b]->next;
	      list[b]->next = list[a];
	      list[a] = list[b];
	      list[b] = temp;

	    }
	}
    }

  printf (" MST is %f\n", mst);
}

void
Updatenode (struct List *list[], int u, int v, float w)
{
  struct List *temp;
  bool flag = false;

  temp = list[v];
  if (!flag && temp)
    {
      if (temp->i == u)
	flag = true;
      else
	temp = temp->next;
    }
  temp->w = w;
  flag = false;
  temp = list[u];
  if (!flag && temp)
    {
      if (temp->i == v)
	flag = true;
      else
	temp = temp->next;
    }
  temp->w = w;

}

void
Deleteedge (struct List *list[], int u, int v)
{
  struct List *temp, *temp1;
  bool flag = false;

  temp = list[v];
  temp1 = NULL;
  if (!flag && temp)
    {
      if (temp->i == u)
	flag = true;
      else
	{
	  temp1 = temp;
	  temp = temp->next;
	}
    }
  if (temp1)
    temp1->next = temp->next;
  else
    list[v] = list[v]->next;
  free (temp);
  flag = false;
  temp = list[u];
  temp1 = NULL;
  if (!flag && temp)
    {
      if (temp->i == v)
	flag = true;
      else
	{
	  temp1 = temp;
	  temp = temp->next;
	}
    }
  if (temp1)
    temp1->next = temp->next;
  else
    list[u] = list[u]->next;
  free (temp);
}

void
CheckMST (struct List *MST[], struct List *list[], int n, int u, int v,
	  float w)
{
  bool V[n];
  float M[n], min = INT_MAX;
  int i;
  int A[n], B[n];
  struct List *temp;

  Deleteedge (MST, u, v);
  BFS (MST, v, n, V, M, A, B);
  for (i = 0; i < n; ++i)
    {
      temp = list[i];
      while (temp)
	{
	  if (V[i] != V[temp->i] && temp->w < min)
	    {
	      min = temp->w;
	      u = i;
	      v = temp->i;
	    }
	  temp = temp->next;
	}

    }


  MST[u] = newedge (MST[u], v, min);
  MST[v] = newedge (MST[v], u, min);

}

void
UpdateMST (struct List *MST[], struct List *list[], int n, int u, int v,
	   float w)
{
  bool V[n];
  float M[n];
  int A[n], B[n];
  BFS (MST, v, n, V, M, A, B);
  if (M[u] > w)
    {
      MST[u] = newedge (MST[u], v, w);
      MST[v] = newedge (MST[v], u, w);
      Deleteedge (MST, A[u], B[u]);
    }

}

void
Update (struct List *MST[], struct List *list[], int n, int u, int v, float w)
{

  int i, j, a, b;
  bool graph = false, mst = false, flag = false;
  struct List *temp;
  temp = MST[u];
  while (!mst && temp)
    {
      if (temp->i == v)
	mst = true;
      else
	temp = temp->next;
    }

  temp = list[u];
  while (!graph && temp)
    {
      if (temp->i == v)
	graph = true;
      else
	temp = temp->next;
    }

  if (graph)
    {
      if (temp->w < w)
	{
	  flag = true;
	}
      Updatenode (list, u, v, w);
      if (!w)
	Deleteedge (list, u, v);
      if (mst)
	{


	  Updatenode (MST, u, v, w);
	  if (flag)
	    {			//value increased, mst may change
	      //   printf("jkfsd");
	      CheckMST (MST, list, n, u, v, w);
	    }
	  else
	    {			//value decreased , mst will not change,do nothing 
	      if (!w)
		CheckMST (MST, list, n, u, v, w);
	    }
	}

      else
	{
	  if (flag)
	    {			//value increased, it can not come to mst, do nothing

	    }
	  else
	    {			//value decreased , it can come to mst
	      UpdateMST (MST, list, n, u, v, w);
	    }


	}

    }
  else
    {				//edge is not in the graph
      list[u] = newedge (list[u], v, w);
      list[v] = newedge (list[v], u, w);
      UpdateMST (MST, list, n, u, v, w);

    }
}

void
main ()
{
  int i, n = 20000, l, r = -1, m = 0, j, k, w;
  struct List *list[n], *MST[n], *temp;
  struct EdgeList *elist[100000];
  float mst;
  for (i = 0; i < n - 1; ++i)
    {
      list[i] = NULL;
      MST[i] = NULL;
    }
  for (i = 0; i < n - 1; ++i)
    {
      j = i;
      for (k = 0; k < n / 100; ++k)
	{
	  j = j + rand () % n / 4 + 1;
	  if (j >= n - 1)
	    {
	      j = n - 1;
	      k = n;
	    }
	  w = rand () % 10 + 1;
	  if (!((i + j) % 10) * 1 * r + w)
	    w++;
	  elist[m++] = newedgelist (i, j, ((i + j) % 10) * 1 * r + w);
	  list[i] = newedge (list[i], j, ((i + j) % 10) * 1 * r + w);
	  list[j] = newedge (list[j], i, ((i + j) % 10) * 1 * r + w);
	  if (m % 10 < 2)
	    r = r * (-1);
	}
    }
  printf ("%d\n", m);


  //for (j = 0; j < m; ++j)

  //printf ("%d %d %f \n", elist[j]->i, elist[j]->j, elist[j]->w);

  Krushkal (elist, n, m);
  Krushkalone (elist, MST, n, m);

//Update(MST,list,n,4,5,10);
  mst = 0;
  for (k = 0; k < n; ++k)
    {
      temp = MST[k];
      while (temp)
	{
	  mst += temp->w;
	  //printf ("(%d,%d %f)", k, temp->i, temp->w);
	  temp = temp->next;
	}

    }
  printf ("\nMST is...... %f:\n", mst / 2);
  Update (MST, list, n, 2, 4, -500);
  mst = 0;
  for (k = 0; k < n; ++k)
    {
      temp = MST[k];
      while (temp)
	{
	  mst += temp->w;
	  //printf ("(%d,%d %f)", k, temp->i, temp->w);
	  temp = temp->next;
	}

    }

  printf ("MST is %f:", mst / 2);
}

