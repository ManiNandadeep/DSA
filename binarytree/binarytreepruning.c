#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*lc;
    struct Node*rc;
};
struct Node*newNode(int key)
{
    struct Node*temp=malloc(sizeof(struct Node));
    temp->data=key;
    temp->lc=NULL;
    temp->rc=NULL;
    return temp;
}
struct Node*treeprune(struct Node*node)
{
    if(node==NULL) return NULL;
    node->lc=treeprune(node->lc);
    node->rc=treeprune(node->rc);
    if(node->data==0 && node->lc==NULL && node->rc==NULL)
        return NULL;
    return node; 
}
void preorder(struct Node*node)
{
    if(node==NULL)
        return;
    printf("%d",node->data);
    preorder(node->lc);
    preorder(node->rc);
}
int main(void)
{
    struct Node*root=newNode(1);
    root->lc=newNode(0);
    root->rc=newNode(1);
    root->lc->lc=newNode(0);
    root->lc->rc=newNode(0);
    root->rc->lc=newNode(0);
    root->rc->rc=newNode(1);
    struct Node*modified=treeprune(root);
    preorder(modified);
    return 0;
}