#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node*lc,*rc;
};
void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
struct Node*newNode(int item)
{
    struct Node*tmp=(struct Node*)malloc(sizeof(struct Node));
    tmp->data=item;
    tmp->lc= tmp->rc=NULL;
    return tmp;
}
void printInorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
    printInorder(node->lc); 
    printf("%d ", node->data); 
    printInorder(node->rc); 
}
void correctBSTUtil(struct Node*root,struct Node**first,struct Node**middle,struct Node**last,struct Node**prev)
{
    if(root)
    {
        correctBSTUtil(root->lc,first,middle,last,prev);
        if(*prev && root->data < (*prev)->data)
        {
            if(!*first)
            {
                *first=*prev;
                *middle=root;
            }
            else
                *last=root;
        }
        *prev=root;
        correctBSTUtil(root->rc,first,middle,last,prev);
    }
}
void correctBST(struct Node*root)
{
    struct Node*first,*middle,*last,*prev;
    first=middle=last=prev=NULL;
    correctBSTUtil(root,&first,&middle,&last,&prev);
    if(first && last)
        swap(&(first->data),&(last->data));
    else if(first && middle)
    {
        swap(&(first->data),&(middle->data));
    }
}
int main() 
{   
    struct Node *root = newNode(6); 
    root->lc        = newNode(10); 
    root->rc       = newNode(2); 
    root->lc->lc  = newNode(1); 
    root->lc->rc = newNode(3); 
    root->rc->rc = newNode(12); 
    root->rc->lc = newNode(7); 
  
    printf("Inorder Traversal of the original tree \n"); 
    printInorder(root); 
  
    correctBST(root); 
  
    printf("\nInorder Traversal of the fixed tree \n"); 
    printInorder(root); 
  
    return 0; 
} 