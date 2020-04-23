#include<stdio.h>
#include<stdlib.h>

struct BST
{
  long long int key;
  struct BST *left, *right;
};

struct List
{
  struct BST *node;
  struct List *next;
};

struct BST *
newNode (long long int key)
{
  struct BST *temp = (struct BST *) malloc (sizeof (struct BST));
  temp->key = key;
  temp->left = temp->right = NULL;
  return temp;
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
      return node;
    }
  else if (node->key < X)
    {
      node->right = Delete (node->right, X);
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

long long int
Rangecount (struct BST *node, long long int l, long long r)
{

  if (!node || l>r)
    return 0;

  if (node->key > r)
    return Rangecount (node->left, l, r);

  if (node->key < l)
    return Rangecount (node->right, l, r);


  return 1 + Rangecount (node->left, l, r) + Rangecount (node->right, l, r);


}


void
Rangelist (struct BST *node, long long int l, long long r, struct List **list)
{

  if (node)
    {

      if (node->key > r)
	Rangelist (node->left, l, r, &*list);

      else if (node->key < l)
	Rangelist (node->right, l, r, &*list);


      else
	{
	  Rangelist (node->right, l, r, &*list);
	  struct List *temp = (struct List *) malloc (sizeof (struct List));
	  temp->node = node;
	  temp->next = *list;
	  *list = temp;

	  Rangelist (node->left, l, r, &*list);
	}

    }

}

struct BST *
LCA (struct BST *node, struct BST *l, struct BST *r)
{
  if (!node || l->key > r->key)
    return NULL;

  // If r smaller than root, then LCA lies in left 
  if (node->key > r->key)
    return LCA (node->left, l, r);

  // If l greater than root, then LCA lies in right 
  if (node->key < l->key)
    return LCA (node->right, l, r);

  return node;
}

struct BST *
Successor (struct BST *node, struct BST *root)
{
  if (!node)
    return node;
  if (node->right)
    {
      node = node->right;
      while (node->left)
	node = node->left;
      return node;
    }
  else
    {

      struct BST *succ = NULL;
      while (node != root)
	{
	  if (node->key < root->key)
	    {
	      succ = root;
	      root = root->left;
	    }
	  else
	    {
	      root = root->right;
	    }

	}
      return succ;
    }

}

struct BST *
Predecessor (struct BST *node, struct BST *root)
{
  if (!node)
    return node;
  if (node->left)
    {
      node = node->left;
      while (node->right)
	node = node->right;
      return node;
    }
  else
    {

      struct BST *pred = NULL;
      while (node != root)
	{
	  if (node->key < root->key)
	    root = root->left;
	  else
	    {
	      pred = root;
	      root = root->right;
	    }

	}
      return pred;
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
      node->key = A[m];

      node->left = CreateBBST (A, l, m - 1);

      node->right = CreateBBST (A, m + 1, r);

    }

  return node;
}

void
main ()
{
  long long int i, n = 1, A[100000], l, r, c;
  struct BST *root = NULL;
  struct List *list;
  A[0] = 5314;
  for (i = 1; i < n; ++i)
    A[i] = rand () % 10 + 1 + A[i - 1];
  root = CreateBBST (A, 0, n - 1);
  Insert (root, 13);
  Insert (root, 452);
  Insert (root, 7653);
  Delete(root,13);
  Inorder(root);

}



