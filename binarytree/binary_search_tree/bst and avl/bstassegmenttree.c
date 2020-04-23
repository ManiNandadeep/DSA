

#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
struct BST
{

  long long int key, value, sum, max, min;

  struct BST *left, *right;

};




int
Max (int x, int y)
{

  if (x < y)

    return y;

  else

    return x;

}




void
NodeUpdate (long long int A[], struct BST *node)
{

  if (node)

    {
      node->max = node->min = node->key;
      node->sum = node->value;

      if (node->left)
	{

	  if (A[node->left->min] < A[node->min])
	    node->min = node->left->min;

	  if (A[node->left->max] > A[node->max])
	    node->max = node->left->max;

	  node->sum += node->left->sum;

	}

      if (node->right)
	{

	  if (A[node->right->min] < A[node->min])
	    node->min = node->right->min;

	  if (A[node->right->max] > A[node->max])
	    node->max = node->right->max;

	  node->sum += node->right->sum;

	}


    }


}

long long int
RangeMax (long long int A[], struct BST *node, long long int l, long long r,
	  long long int s, long long int e)
{

  if (node)
    {

      if (s >= l && e <= r)
	return node->max;

      else if (e < l || r < s)
	return -1;
      else
	{
	  long long int max, m1, m = (s + e) / 2;
	  if (node->key >= l && node->key <= r)
	    max = node->key;
	  else
	    max = -1;
	  m1 = RangeMax (A, node->right, l, r, m + 1, e);
	  if (max < 0)
	    max = m1;
	  if (max > -1 && m1 > -1 && A[m1] > A[max])
	    max = m1;
	  m1 = RangeMax (A, node->left, l, r, s, m - 1);
	  if (max < 0)
	    max = m1;
	  if (max > -1 && m1 > -1 && A[m1] > A[max])
	    max = m1;

	  return max;
	}

    }
  return -1;
}

long long int
RangeMin (long long int A[], struct BST *node, long long int l, long long r,
	  long long int s, long long int e)
{

  if (node)
    {

      if (s >= l && e <= r)
	return node->min;

      else if (e < l || r < s)
	return -1;
      else
	{
	  long long int min, m1, m = (s + e) / 2;
	  if (node->key >= l && node->key <= r)
	    min = node->key;
	  else
	    min = -1;
	  m1 = RangeMin (A, node->right, l, r, m + 1, e);
	  if (min < 0)
	    min = m1;
	  if (min > -1 && m1 > -1 && A[m1] < A[min])
	    min = m1;
	  m1 = RangeMin (A, node->left, l, r, s, m - 1);
	  if (min < 0)
	    min = m1;
	  if (min > -1 && m1 > -1 && A[m1] < A[min])
	    min = m1;

	  return min;
	}

    }
  return -1;
}

long long int
PreSum (struct BST *node, long long int i)
{
  long long int sum = 0;

  while (node)
    {
      if (node->key > i)
	node = node->left;
      else if (node->key < i)
	{
	  if (node->left)
	    sum += node->left->sum;
	  sum += node->value;
	  node = node->right;

	}
      else
	{
	  if (node->left)
	    sum += node->left->sum;
	  sum += node->value;
	  return sum;
	}
    }
  return 0;
}


void
Update (long long int A[], struct BST *node, long long int i, long long X)
{

  if (node)
    {

      if (node->key > i)
	Update (A, node->left, i, X);
      else if (node->key < i)
	Update (A, node->right, i, X);

      else
	{
	  A[i] = X;
	  node->value = X;

	}
      NodeUpdate (A, node);
    }

}




struct BST *
CreateBBST (long long int A[], long long int l, long long int r)
{

  struct BST *node = NULL;

  if (l <= r)

    {


      long long int m = (l + r) / 2;

      node = (struct BST *) malloc (sizeof (struct BST));

      node->key = m;

      node->value = A[m];

      node->left = CreateBBST (A, l, m - 1);


      node->right = CreateBBST (A, m + 1, r);

      NodeUpdate (A, node);

    }


  return node;

}

void
Preorder (struct BST *node)
{
  if (node)
    {
      printf ("%lld: %lld  ", node->key, node->sum);

      Preorder (node->left);
      Preorder (node->right);
    }
}

long long int
MaxGap (long long int A[], struct BST *node, long long int l, long long int r,
	long long int n)
{
  return
    A[RangeMax (A, node, l, r, 0, n - 1)] -
    A[RangeMin (A, node, l, r, 0, n - 1)];
}


void
main ()
{

  long long int i, n = 100000, A[100000], l, r, c, m;

  struct BST *root = NULL;
  m = 1000;

  root = CreateBBST (A, 0, n - 1);
  for (i = 0; i < n; ++i)

    A[i] = rand () % m + 1;
  for (i = 0; i < n; i++)
    Update (A, root, i, A[i]);

  printf ("\n%lld", PreSum (root, n / 1000));
  l = 1437;
  r = 95456;


  printf ("\n%lld", MaxGap (A, root, l, r, n));
}
