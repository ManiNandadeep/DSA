#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct Node{
    int data;
    struct Node*lc,*rc;
};
int isBSTUtil(struct Node*node,int min,int max)
{
    if(node==NULL)
        return 1;
    if(node->data < min || node->data >max)
        return 0;
    return 
        isBSTUtil(node->lc,min,node->data-1)&&
        isBSTUtil(node->rc,node->data+1,max);
}
int isBST(struct Node*node)
{
    return(isBSTUtil(node,INT_MIN,INT_MAX));
}
struct Node* newNode(int data) 
{ 
  struct Node* node = (struct Node*) 
                       malloc(sizeof(struct Node)); 
  node->data = data; 
  node->lc = NULL; 
  node->rc = NULL; 
  
  return(node); 
} 
int main() 
{ 
  struct Node *root = newNode(4); 
  root->lc        = newNode(2); 
  root->rc       = newNode(5); 
  root->lc->lc  = newNode(1); 
  root->lc->rc = newNode(3);  
  
  if(isBST(root)) 
    printf("Is BST"); 
  else
    printf("Not a BST"); 
      
  return 0; 
}   