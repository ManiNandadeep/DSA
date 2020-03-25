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
void bst_to_maxheap(struct Node*root,int*arr,int*i)
{
    if(root==NULL)
        return ;
    bst_to_maxheap(root->lc,arr,i);
    bst_to_maxheap(root->rc,arr,i);
    root->data=arr[++*i];
}
void postorder(struct Node*root)
{
    if(root==NULL)
        return ;
    postorder(root->lc);
    postorder(root->rc);
    printf("%d ",root->data);
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
    bst_to_maxheap(root,arr,&j);
    postorder(root);
    return 0;
}