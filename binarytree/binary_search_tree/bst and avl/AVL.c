
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
struct BST
{
  long long int key;
  int height;
  long long int count;
  struct BST *left, *right;
};


struct BST *
newNode (long long int key)
{
  struct BST *temp = (struct BST *) malloc (sizeof (struct BST));
  temp->key = key;
  temp->left = temp->right = NULL;
  temp->height = 0;
  temp->count = 1;
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
	return 1 + node->left->count + node->right->count;

      else if (node->left)
	return 1 + node->left->count;
      else if (node->right)
	return 1 + node->right->count;
      else
	return 1;

    }

  else
    return 0;
}

bool
AVL (struct BST * node)
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
      printf ("%lld  ", node->key);
      Inorder (node->right);
    }
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
  if(!node)
    return 0;
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

      Z->height = Height (Z);
      X->height = Height (X);
      Y->height = Height (Y);
      Z->count = Count (Z);
      X->count = Count (X);
      Y->count = Count (Y);
      return Y;

    }
  else if (c == 3)
    {

      T2 = Y->left;
      Y->left = Z;
      Z->right = T2;
      Z->height = Height (Z);
      X->height = Height (X);
      Y->height = Height (Y);
      Z->count = Count (Z);
      X->count = Count (X);
      Y->count = Count (Y);
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

      Z->height = Height (Z);
      Y->height = Height (Y);
      X->height = Height (X);
      Z->count = Count (Z);
      Y->count = Count (Y);
      X->count = Count (X);

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
      Z->height = Height (Z);
      Y->height = Height (Y);
      X->height = Height (X);
      Z->count = Count (Z);
      Y->count = Count (Y);
      X->count = Count (X);
      return X;
    }


}

struct BST *
Insert (struct BST *node, long long int key)
{
  // If the BST is empty, create a  new BST
  if (!node)
    return newNode (key);

  // Otherwise, insert in left subtree or right subtree 
  if (key < node->key)
    node->left = Insert (node->left, key);
  else if (key > node->key)
    node->right = Insert (node->right, key);
  node->height = Height (node);
  node->count = Count (node);
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
      node->height = Height (node);
      node->count = Count (node);
      if (!AVL (node))
	node = Rotate (node);

      return node;
    }
  else if (node->key < X)
    {
      node->right = Delete (node->right, X);
      node->height = Height (node);
      node->count = Count (node);

      if (!AVL (node))
	node = Rotate (node);
      return node;
    }
  if (node->left && node->right)
    {
      struct BST *temp = node->left;
      while (temp->right)
	temp = temp->right;
      node->key = temp->key;
      node->left = Delete (node->left, temp->key);
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

  for (i = 1; i < n / 2; ++i)
    root = Delete (root, A[2 * i]);
  n = n / 2 + 2;

  for (i = 0; i < 11; ++i)
    printf ("%lld %lld \n", 5000 * i + 1, FindRank (root, i * 5000 + 1)->key);

}

