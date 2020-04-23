#include<limits.h>
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
struct BST
{
  long long int key;
  int height;
  long long int count, c, min, max, mingap;
  struct BST *left, *right;
};


struct BST *
newNode (long long int key)
{
  struct BST *temp = (struct BST *) malloc (sizeof (struct BST));
  temp->key = temp->max = temp->min = key;
  temp->left = temp->right = NULL;
  temp->height = 0;
  temp->count = 1;
  temp->c = 1;
  temp->mingap = INT_MAX;
  return temp;
}


int
Max (int x, int y)
{
  if (x < y)
    return y;
  else
    return x;
}

int
Min (int x, int y)
{
  if (x < y)
    return x;
  else
    return y;
}

int
Height (struct BST *node)
{
  if (node)
    {
      if (node->left && node->right)
	return 1 + Max (node->left->height, node->right->height);

      else if (node->left)
	return 1 + node->left->height;
      else if (node->right)
	return 1 + node->right->height;
      else
	return 0;

    }

  else
    return -1;
}

long long int
Count (struct BST *node)
{
  if (node)
    {
      if (node->left && node->right)
	return node->c + node->left->count + node->right->count;

      else if (node->left)
	return node->c + node->left->count;
      else if (node->right)
	return node->c + node->right->count;
      else
	return node->c;

    }

  else
    return 0;
}

void
Update (struct BST *node)
{
  node->max = node->min = node->key;
  if (node->left && node->left->max > node->max)
    node->max = node->left->max;
  if (node->right && node->right->max > node->max)
    node->max = node->right->max;
  if (node->left && node->left->min < node->min)
    node->min = node->left->min;
  if (node->right && node->right->min < node->min)
    node->min = node->right->min;

  node->mingap = INT_MAX;
  if (node->left)
    node->mingap =
      Min (node->left->mingap,
	   Min (node->mingap, node->key - node->left->max));
  if (node->right)
    node->mingap =
      Min (node->right->mingap,
	   Min (node->mingap, node->right->min - node->key));

  node->height = Height (node);
  node->count = Count (node);
}

bool
AVL (struct BST *node)
{
  if (abs (Height (node->left) - Height (node->right)) < 2)
    return true;
  else
    return false;
}

void
Inorder (struct BST *node)
{
  if (node)
    {
      Inorder (node->left);
      printf ("%lld: %lld %lld %lld %lld  ", node->key, node->count,
	      node->min, node->max, node->mingap);
      Inorder (node->right);
    }
}

long long int
Pre (struct BST *node)
{
  if (node)
    {
      return Pre (node->left) + Pre (node->right) + 1;
    }
  else
    return 0;
}

struct BST *
Search (struct BST *node, long long int X)
{

  while (node)
    {
      if (X == node->key)
	return node;
      else if (X < node->key)
	node = node->left;
      else
	node = node->right;
    }
  return NULL;
}

struct BST *
FindRank (struct BST *node, long long int rank)
{
  long long int r;
  if (node && rank > 0 && rank < node->count + 1)
    {
      while (node)
	{
	  if (node->right)
	    r = node->right->count + 1;
	  else
	    r = 1;
	  if (r == rank)
	    return node;
	  else if (rank > r)
	    {
	      node = node->left;
	      rank = rank - r;
	    }
	  else
	    node = node->right;
	}
    }
  return NULL;
}

long long int
Rank (struct BST *node, long long int X)
{
  long long int rank = 1;

  while (node)
    {
      if (X == node->key)
	{
	  if (node->right)
	    rank += node->right->count;
	  return rank;
	}
      else if (X < node->key)
	{
	  rank++;
	  if (node->right)
	    rank += node->right->count;
	  node = node->left;
	}
      else
	node = node->right;
    }
  return rank;
}

long long int
Rangecount (struct BST *node, long long int l, long long int r)
{
  long long int count;

  count = Rank (node, l) - Rank (node, r);
  if (Search (node, l))
    count++;
  return count;
}

struct BST *
Rotate (struct BST *Z)
{
  struct BST *X, *Y, *T1, *T2, *T3, *T4;
  int c = 0;
  if (Height (Z->left) + 1 == Z->height)
    Y = Z->left;
  else
    {
      Y = Z->right;
      c++;
    }
  c = c * 2;
  if (Height (Y->left) + 1 == Y->height)
    X = Y->left;
  else
    {
      X = Y->right;
      c++;
    }

  if (c == 0)
    {
      T3 = Y->right;
      Y->right = Z;
      Z->left = T3;
      Update (Z);
      Update (X);
      Update (Y);
      return Y;

    }
  else if (c == 3)
    {

      T2 = Y->left;
      Y->left = Z;
      Z->right = T2;
      Update (Z);
      Update (X);
      Update (Y);

      return Y;
    }
  else if (c == 1)
    {

      T2 = X->left;
      T3 = X->right;
      Y->right = T2;
      Z->left = T3;
      X->left = Y;
      X->right = Z;

      Update (Z);
      Update (Y);
      Update (X);
      return X;

    }
  else
    {
      T2 = X->left;
      T3 = X->right;
      Y->left = T3;
      Z->right = T2;
      X->left = Z;
      X->right = Y;

      Update (Z);
      Update (Y);
      Update (X);
      return X;
    }


}

struct BST *
Insert (struct BST *node, long long int key)
{
  // If the BST is empty, create a  new BST
  if (!node)
    return newNode (key);
  if (key < node->key)
    node->left = Insert (node->left, key);
  else if (key > node->key)
    node->right = Insert (node->right, key);
  else
    {
      node->count++;
      node->c++;
      node->mingap = 0;
      return node;
    }
  Update (node);
  //node->height = Height (node);
  //node->count = Count (node);
  if (!AVL (node))
    {
      node = Rotate (node);
    }
  return node;
}

struct BST *
Delete (struct BST *node, long long int X)
{
  if (!node)
    return node;

  // Recursive calls for ancestors of 
  // node to be deleted 
  if (node->key > X)
    {
      node->left = Delete (node->left, X);
      //node->height = Height (node);
      // node->count = Count (node);
      Update (node);
      if (!AVL (node))
	node = Rotate (node);

      return node;
    }
  else if (node->key < X)
    {
      node->right = Delete (node->right, X);
      //node->height = Height (node);
      //node->count = Count (node);
      Update (node);
      if (!AVL (node))
	node = Rotate (node);
      return node;
    }
  else
    {
      node->c--;
      node->count--;
      if (node->c == 1)
	node->mingap = INT_MAX;
    }

  if (node->c == 0)
    {

      if (node->left && node->right)
	{
	  struct BST *temp = node->left;
	  while (temp->right)
	    temp = temp->right;
	  node->key = temp->key;
	  node->c = temp->c;
	  node->left = Delete (node->left, temp->key);
	  //node->count = Count (node);
	  Update (node);
	}
      else
	{
	  struct BST *child;
	  if (node->left)

	    child = node->left;
	  else
	    child = node->right;
	  free (node);
	  return child;
	}

    }
  else
    return node;

}

struct BST *
Successor (struct BST *node, long long int X)
{
  if (!node)
    return node;

  struct BST *succ = NULL;
  while (node)
    {
      if (node->key > X)
	{
	  succ = node;
	  node = node->left;
	}
      else
	{
	  node = node->right;
	}

    }
  return succ;


}


struct BST *
Predecessor (struct BST *node, long long int X)
{
  if (!node)
    return node;

  struct BST *pred = NULL;
  while (node)
    {
      if (node->key > X)
	node = node->left;
      else
	{
	  pred = node;
	  node = node->right;
	}

    }
  return pred;


}

long long int
MaxGap (struct BST *node, long long int l, long long int r)
{
  if (l <= r)
    {
      if (!Search (node, l))
	l = Successor (node, l)->key;
      if (!Search (node, r))
	r = Predecessor (node, r)->key;

      return (r - l);
    }
  return -1;
}

long long int
MinGap2 (struct BST *node, long long int l)
{
  long long int min = INT_MAX;
  while (node)
    {
      if (l > node->key)
	node = node->right;
      else if (l < node->key)
	{
	  if (node->right)
	    {
	      min =
		Min (Min (min, node->right->mingap),
		     node->right->min - node->key);
	    }
	  min = Min (min, node->key - node->left->max);
	  node = node->left;
	}
      else
	{
	  if (node->right)
	    {
	      min =
		Min (Min (min, node->right->mingap),
		     node->right->min - node->key);
	    }
	  return min;

	}

    }
}

long long int
MinGap3 (struct BST *node, long long int r)
{
  long long int min = INT_MAX;
  while (node)
    {
      if (r < node->key)
	node = node->left;
      else if (r > node->key)
	{
	  if (node->left)
	    {
	      min =
		Min (Min (min, node->left->mingap),
		     node->key - node->left->max);
	    }
	  min = Min (min, node->right->min - node->key);
	  node = node->right;
	}
      else
	{

	  if (node->left)
	    {
	      min =
		Min (Min (min, node->left->mingap),
		     node->key - node->left->max);
	    }
	  return min;

	}
    }

}

long long int
MinGap1 (struct BST *node, long long int l, long long int r)
{
  if (l <= r && node)
    {

      if (node->key >= l && node->key <= r)
	return node->mingap;

      if (node->key <= l)
	return MinGap1 (node->right, l, r);
      else if (node->key >= r)
	return MinGap1 (node->left, l, r);
      else
	{
	  long long int min = INT_MAX;
	  min = Min (MinGap2 (node->left, l), MinGap3 (node->right, r));
	  if (node->left && node->left->key >= l)
	    min = Min (min, node->key - node->left->max);
	  if (node->right && node->right->key <= r)
	    min = Min (min, node->right->min - node->key);

	  return min;
	}

    }
  return INT_MAX;
}

long long int
MinGap (struct BST *node, long long int l, long long int r)
{
  if (l <= r)
    {
      if (!Search (node, l))
	l = Successor (node, l)->key;
      if (!Search (node, r))
	r = Predecessor (node, r)->key;

      return MinGap1 (node, l, r);
    }
  return INT_MAX;
}

void
main ()
{
  long long int i, n = 100000, A[100000], l, r, c;
  struct BST *root = NULL;
  struct List *list;
  A[0] = 54;
  for (i = 1; i < n; ++i)
    {
      A[i] = rand () % 10 + 1 + A[i - 1];
      root = Insert (root, A[i]);
    }
  root = Insert (root, 42);
  root = Insert (root, 7);
  root = Insert (root, 105);

  printf ("%lld\n", MinGap (root, 14, 60000));

  for (i = 6; i < n; ++i)
    root = Delete (root, A[i]);


  Inorder (root);

  printf ("\n%lld\n", MinGap (root, 14, 105));

}
