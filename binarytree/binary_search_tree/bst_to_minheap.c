#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*lc,*rc;
};
struct Node*newnode(int item)
{
    struct Node*tmp=(struct Node*)malloc(sizeof(struct Node));
    tmp->data=item;
    tmp->lc= tmp->rc=NULL;
    return tmp;
}
void inorder(struct Node*root,int*arr,int*i)
{
    if(root==NULL)
        return;
    inorder(root->lc,arr,i);
    arr[++*i]=root->data;
    inorder(root->rc,arr,i);    
}
void bst_to_minheap(struct Node*root,int*arr,int*i)
{
    if(root==NULL)
        return ;
    root->data=arr[++*i];
    bst_to_minheap(root->lc,arr,i);
    bst_to_minheap(root->rc,arr,i);
}
void preorder(struct Node*root)
{
    if(root==NULL)
        return ;
    printf("%d ",root->data);
    preorder(root->lc);
    preorder(root->rc);
}
int main(void)
{
    struct Node*root=newnode(4);
    root->lc=newnode(2);
    root->rc=newnode(6);
    root->lc->lc=newnode(1);
    root->lc->rc=newnode(3);
    root->rc->lc=newnode(5);
    root->rc->rc=newnode(7);
    int *arr=malloc(255*sizeof(int));
    int i=-1;
    inorder(root,arr,&i);
    int j=-1;
    bst_to_minheap(root,arr,&j);
    preorder(root);
    return 0;
}