#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct Node{
    int data;
    struct Node*lc,*rc;
};
struct Node*newNode(int data)
{
    struct Node*tmp=(struct Node*)malloc(sizeof(struct Node));
    tmp->data=data;
    tmp->lc=tmp->rc=NULL;
    return tmp;
}
int min(int a,int b)
{
    if(a<b) return a;
    return b;
}
int max(int a,int b)
{
    if(a>b) return a;
    return b;
}
void inorder(struct Node* root) 
{ 
    if (root) 
    { 
        inorder(root->lc); 
        printf("%d ", root->data); 
        inorder(root->rc); 
    } 
} 
int maxDiffUtil(struct Node*t,int*res)
{
    if(t==NULL)
        return INT_MAX;
    
    // if leaf nodes then return node's value
    if(t->lc == NULL && t->rc == NULL)
        return t->data;
    // recursively call left and right subtree for min value
    int val=min(maxDiffUtil(t->lc,res),maxDiffUtil(t->rc,res));
    //updating res if node value -min value is bigger than res
    *res=max(*res,t->data - val);
    // returning min  value got so far
    return min(val,t->data);
}
int maxDiff(struct Node*root)
{
    int res=INT_MIN;
    maxDiffUtil(root,&res);
    return res;
}
int main(void)
{
    struct Node*root=newNode(2);
    root->lc=newNode(7);
    root->lc->lc=newNode(4);
    root->lc->rc=newNode(5);
    root->lc->rc->lc=newNode(1);
    root->rc=newNode(9);
    printf("%d",maxDiff(root));
    return 0;
}