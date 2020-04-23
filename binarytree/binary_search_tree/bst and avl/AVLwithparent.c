#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
struct BST
{
  long long int key;
  int height;
  long long int count;
  struct BST *left, *right, *parent;
};


struct BST *
newNode (long long int key)
{
  struct BST *temp = (struct BST *) malloc (sizeof (struct BST));
  temp->key = key;
  temp->left = temp->right = temp->parent = NULL;
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
      printf ("  %lld %lld", node->key, node->count);
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


void
Rotate (struct BST **node, struct BST *Z)
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
      if (Z->parent)
	{
	  if (Z->parent->left == Z)
	    Z->parent->left = Y;
	  else
	    Z->parent->right = Y;
	}
      else
	{
	  *node = Y;
	}
      T3 = Y->right;
      Y->right = Z;
      Z->left = T3;
      Y->parent = Z->parent;
      Z->parent = Y;
      if (T3)
	T3->parent = Z;

      Z->height = Height (Z);
      X->height = Height (X);
      Y->height = Height (Y);
      Z->count = Count (Z);
      X->count = Count (X);
      Y->count = Count (Y);
    }
  else if (c == 3)
    {
      if (Z->parent)
	{
	  if (Z->parent->left == Z)
	    Z->parent->left = Y;
	  else
	    Z->parent->right = Y;
	}
      else
	{
	  *node = Y;
	}

      T2 = Y->left;
      Y->left = Z;
      Z->right = T2;
      Y->parent = Z->parent;
      Z->parent = Y;
      if (T2)
	T2->parent = Z;
      Z->height = Height (Z);
      X->height = Height (X);
      Y->height = Height (Y);
      Z->count = Count (Z);
      X->count = Count (X);
      Y->count = Count (Y);

    }
  else if (c == 1)
    {
      if (Z->parent)
	{
	  if (Z->parent->left == Z)
	    Z->parent->left = X;
	  else
	    Z->parent->right = X;
	}
      else
	{
	  *node = X;
	}
      T2 = X->left;
      T3 = X->right;
      Y->right = T2;
      Z->left = T3;
      X->parent = Z->parent;
      Z->parent = X;
      Y->parent = X;
      if (T2)
	T2->parent = Y;
      if (T3)
	T3->parent = Z;
      X->left = Y;
      X->right = Z;

      Z->height = Height (Z);
      Y->height = Height (Y);
      X->height = Height (X);
      Z->count = Count (Z);
      Y->count = Count (Y);
      X->count = Count (X);
    }
  else
    {
      if (Z->parent)
	{
	  if (Z->parent->left == Z)
	    Z->parent->left = X;
	  else
	    Z->parent->right = X;
	}
      else
	{
	  *node = X;
	}

      T2 = X->left;
      T3 = X->right;
      Y->left = T3;
      Z->right = T2;
      X->parent = Z->parent;
      Z->parent = X;
      Y->parent = X;
      if (T2)
	T2->parent = Z;
      if (T3)
	T3->parent = Y;
      X->left = Z;
      X->right = Y;
      Z->height = Height (Z);
      Y->height = Height (Y);
      X->height = Height (X);
      Z->count = Count (Z);
      Y->count = Count (Y);
      X->count = Count (X);

    }


}

void
Insert (struct BST **node, long long int key)
{
  if (!Search (*node, key))
    {
      struct BST *temp = *node;
      // If the BST is empty, create a  new BST
      if (!*node)
	*node = newNode (key);

      else
	{
	  bool flag = true;
	  // struct BST *temp = *node;

	  while (flag)
	    {
	      temp->count++;
	      if (key < temp->key)

		if (temp->left)
		  temp = temp->left;
		else
		  {
		    temp->left = newNode (key);
		    temp->left->parent = temp;
		    flag = false;
		  }
	      else if (key > temp->key)
		{
		  if (temp->right)
		    temp = temp->right;
		  else
		    {
		      temp->right = newNode (key);
		      temp->right->parent = temp;
		      flag = false;
		    }

		}
	      else
		flag = false;

	    }			// end of while loop
//      temp = temp->parent;
	  flag = true;
	  int h;

	  while (flag)
	    {
	      h = Height (temp);
	      if (h > temp->height)
		{
		  temp->height = h;
		  if (!AVL (temp))
		    {
		      Rotate (&*node, temp);
		      flag = false;
		    }
		  else if (temp->parent)
		    temp = temp->parent;
		  else
		    {
		      flag = false;
		    }
		}
	      else
		flag = false;
	    }


	}			//end of else
    }				//end of Insert
}

void
DeleteNode (struct BST **root, struct BST *node)
{

  if (node->left && node->right)
    {
      struct BST *temp = node->left;
      while (temp->right)
	{
	  temp->count--;
	  temp = temp->right;
	}
      node->key = temp->key;
      node = temp;
    }
  struct BST *child, *p = node->parent;
  if (node->left)
    child = node->left;
  else
    child = node->right;
  if (*root == node)
    *root = child;
  if (child)
    child->parent = p;
  if (p)
    if (p->left == node)
      p->left = child;
    else
      p->right = child;
  free (node);
  struct BST *temp = p;
  bool flag;
  if (p)
    flag = true;
  else
    flag = false;
  int h;

  while (flag)
    {
      if (!AVL (temp))
	{
	  Rotate (&*root, temp);
	  temp = temp->parent->parent;
	  if (!temp)
	    flag = false;
	}
      else
	{

	  h = Height (temp);
	  if (h < temp->height)
	    {
	      temp->height = h;

	      if (temp->parent)
		temp = temp->parent;
	      else
		{
		  flag = false;
		}
	    }
	  else
	    flag = false;
	}
    }
}

void
Delete (struct BST **root, long long int X)
{
  struct BST *node = *root;
  if (Search (*root, X))
    {
      while (node)
	{
	  node->count--;
	  if (X == node->key)
	    {
	      DeleteNode (&*root, node);
	      break;
	    }
	  else if (X < node->key)
	    node = node->left;
	  else
	    node = node->right;
	}
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
      Insert (&root, A[i]);

    }
  Insert (&root, 42);
  Insert (&root, 7);
  for (i = 1; i < n / 2; ++i)
    Delete (&root, A[2 * i]);
  n = n / 2 + 2;

  for (i = 0; i < n; ++i)
    printf ("%lld %lld \n", n - i, FindRank (root, n - i)->key);
}
