#include<stdio.h>
#include<stdlib.h>
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
int sumtree(struct Node*root)
{
    if(root==NULL)
        return 0;
    return(sumtree(root->lc)+sumtree(root->rc)+root->data);
}
int tilt_binarytree(struct Node*root)
{
    if(root==NULL)
        return 0;
    return abs(sumtree(root->lc)-sumtree(root->rc));
}
int main(void)
{
    struct Node*root=newNode(1);
    root->lc=newNode(2);
    root->rc=newNode(3);
    printf("%d",tilt_binarytree(root));
    return 0;
}