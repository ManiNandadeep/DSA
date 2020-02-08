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
void postorder(struct Node*node)
{
    if(node==NULL)
        return;
    postorder(node->lc);
    postorder(node->rc);
    printf("%d",node->data);
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
    printf("PostOrder traversal of binary tree using recursion is \n");
    postorder(root);
    return 0;
}