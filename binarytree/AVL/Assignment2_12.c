
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
struct BST
{
  long long int key;
  int height;
  long long int count,index;
  struct BST *left, *right;
};


struct BST *
newNode (long long int key,long long int index)
{
  struct BST *temp = (struct BST *) malloc (sizeof (struct BST));
  temp->key = key;
  temp->left = temp->right = NULL;
  temp->height = 0;
  temp->count = 1;
  temp->index=index;
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

void 
Preorder(struct BST*node)
{
  if(node)
  {
    printf("%lld ",node->key);
    Preorder(node->left);
    Preorder(node->right);
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
Insert (struct BST *node, long long int key,long long int index)
{
  // If the BST is empty, create a  new BST
  if (!node)
    return newNode (key,index);

  // Otherwise, insert in left subtree or right subtree 
  if (key < node->key)
    node->left = Insert (node->left, key,index);
  else if (key > node->key)
    node->right = Insert (node->right, key,index);
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
struct BST* minele(struct BST*root1)
{
  if(!root1)
    return 0;
  while(root1->left)
  {
    root1=root1->left;
  }
  return root1;
}
void
main ()
{
  long long int A[]={6, 2, 8, 4, 9, 3};
  long long int n=sizeof(A)/sizeof(A[0]);
  long long int *B=(long long int*)malloc(n*sizeof(long long int));
  struct BST*root1=NULL;
  long long int i;
  for(i=0;i<n;i++)
  {
    root1=Insert(root1,A[i],i);
    
    B[i]=i;
  }
  struct BST*root2=NULL;
  for(i=0;i<n;i++)
  {
    root2=Insert(root2,B[i],i);
  }
  long long int result=0;
  for(i=0;i<n;i++)
  {
    struct BST*tmp=minele(root1);
    long long index=tmp->index;
    root1=Delete(root1,tmp->key);
    result+=(Rank(root2,index)-1);
    root2=Delete(root2,index);
  }
  printf("%lld",result);
}

