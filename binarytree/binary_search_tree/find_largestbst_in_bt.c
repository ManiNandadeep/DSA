#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
struct Node{
    int data;
    struct Node*lc,*rc;
};
struct Node* newNode(int data) 
{ 
  struct Node* node = (struct Node*) 
                       malloc(sizeof(struct Node)); 
  node->data = data; 
  node->lc = NULL; 
  node->rc = NULL; 
  
  return(node); 
} 
int largestBSTUtil(struct Node*node,int* min_ref,int*max_ref,int* max_size_ref,bool*is_bst_ref)
{
    if(node==NULL)
    {
        *is_bst_ref=1;
        return 0;
    }
    int min=INT_MAX;
    // A flag variable to check whether max(node->lc) < node->data
    bool left_flag=false;
    // A flag variable to check whether min(node->rc) > node->data
    bool right_flag=false;
    int ls,rs;

    *max_ref=INT_MIN;
    ls=largestBSTUtil(node->lc,min_ref,max_ref,max_size_ref,is_bst_ref);
    if(*is_bst_ref==1 && node->data > *max_ref)
        left_flag =true;
    min=*min_ref;
    
    *min_ref=INT_MAX;
    rs=largestBSTUtil(node->rc,min_ref,max_ref,max_size_ref,is_bst_ref);
    if(*is_bst_ref==1 && node->data < *min_ref)
        right_flag=true;
    
    if(min < *min_ref)
        *min_ref=min;
    if(node->data <*min_ref)
        *min_ref=node->data;
    if(node->data >*max_ref)
        *max_ref=node->data;
    
    if(left_flag && right_flag)
    {
        if(ls+rs+1 > *max_size_ref)
            *max_size_ref=ls+rs+1;
        return ls+rs+1;
    }
    else
    {
        *is_bst_ref=0;
        return 0;
    }
}
int largestBST(struct Node*node)
{
    int min=INT_MAX;
    int max=INT_MIN;
    int max_size=0;
    bool is_bst=0;
    largestBSTUtil(node,&min,&max,&max_size,&is_bst);
    return max_size;
}
/* Driver program to test above functions*/
int main() 
{ 
    /* Let us construct the following Tree 
          50 
       /      \ 
     10        60 
    /  \       /  \ 
   5   20    55    70 
            /     /  \ 
          45     65    80 
  */
  
  struct Node *root = newNode(50); 
  root->lc        = newNode(10); 
  root->rc       = newNode(60); 
  root->lc->lc  = newNode(5); 
  root->lc->rc = newNode(20); 
  root->rc->lc = newNode(55); 
  root->rc->lc->lc  = newNode(45); 
  root->rc->rc = newNode(70); 
  root->rc->rc->lc = newNode(65); 
  root->rc->rc->rc = newNode(80); 
  
  /* The complete tree is not BST as 45 is in right subtree of 50. 
     The following subtree is the largest BST 
        60 
      /  \ 
    55    70 
   /     /  \ 
 45     65    80 
  */
  printf(" Size of the largest BST is %d", largestBST(root)); 
  
  return 0; 
} 