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
void inorder(struct Node*node)
{
    if(node==NULL)
        return;
    inorder(node->lc);
    printf("%d",node->data);
    inorder(node->rc);
}
int main(void)
{
    struct Node*root=newNode(1);
    root->lc=newNode(2);
    root->rc=newNode(3);
    root->lc->lc=newNode(4);
    root->lc->rc=newNode(5);
    root->rc->lc=newNode(6);
    root->rc->rc=newNode(7);
    printf("InOrder traversal of binary tree using recursion is \n");
    inorder(root);
    return 0;
}
