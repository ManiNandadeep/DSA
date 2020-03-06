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
int dfs(struct Node*root,int*steps)
{
    if(!root)
        return 0;
    int l=dfs(root->lc,steps);
    int r=dfs(root->rc,steps);
    *steps+=abs(l)+abs(r);
    return root->data+l+r-1;
}
int distributeCoins(struct Node*root)
{
    int*steps;
    *steps=0;
    int tmp=dfs(root,steps);
    return *steps;
}
int main(void)
{
    struct Node*root=newNode(1);
    root->lc=newNode(0);
    root->rc=newNode(0);
    root->lc->rc=newNode(3);
    printf("%d",distributeCoins(root));
    return 0;
}