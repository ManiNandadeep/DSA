//time complexity o(n^2)
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*lc,*rc;
};
struct Node*newNode(int data)
{
    struct Node*node=(struct Node*)malloc(sizeof(struct Node));
    node->data=data;
    node->lc=NULL;
    node->rc=NULL;
    return node;
}
int max(int a,int b)
{
    if(a>b)
        return a;
    return b;
}
int getWidth(struct Node*root,int level);
int height(struct Node*node);
struct Node*newNode(int data);

int getMaxWidth(struct Node*root)
{
    int maxWidth=0;
    int width;
    int h=height(root);
    int i;
    for(i=1;i<=h;i++)
    {
        width=getWidth(root,i);
        if(width > maxWidth)
            maxWidth=width;
    }
    return maxWidth;
}
int getWidth(struct Node*root,int level)
{
    if(root==NULL)
        return 0;
    if(level ==1)
        return 1;
    else if(level>1)
        return getWidth(root->lc,level-1)+getWidth(root->rc,level-1);
}
int height(struct Node*node)
{
    if(node==NULL)
        return 0;
    else
    {
        return 1+max(height(node->lc),height(node->rc));
    }
}
int main() 
{ 
  struct Node *root = newNode(1); 
  root->lc        = newNode(2); 
  root->rc       = newNode(3); 
  root->lc->lc  = newNode(4); 
  root->lc->rc = newNode(5); 
  root->rc->rc = newNode(8);     
  root->rc->rc->lc  = newNode(6);     
  root->rc->rc->rc  = newNode(7);       
  
  /* 
   Constructed bunary tree is: 
          1 
        /  \ 
       2    3 
     /  \     \ 
    4   5     8  
              /  \ 
             6   7 
  */  
  printf("Maximum width is %d \n", getMaxWidth(root));   
  return 0; 
} 