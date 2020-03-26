#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*lc,*rc;
};
struct Node*newNode(int key)
{
    struct Node*temp=malloc(sizeof(struct Node));
    temp->data=key;
    temp->lc=NULL;
    temp->rc=NULL;
    return temp;
}
int getLeafCount(struct Node*node)
{
    if(node ==NULL)
        return 0;
    if(node->lc ==NULL && node->rc ==NULL)
        return 1;
    else
        return getLeafCount(node->lc)+getLeafCount(node->rc);
}
int main(void)
{
    struct Node*root=newNode(1);
    root->lc=newNode(2);
    root->rc=newNode(3);
    root->lc->lc=newNode(4);
    root->lc->rc=newNode(5);
    printf("Leaf count of the tree is %d",getLeafCount(root));
    return 0;
}