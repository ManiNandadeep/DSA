#include<stdio.h>
#include<stdlib.h>
struct Node
{
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
//this function assumes that both n1,n2 are present in the binary tree
struct Node*findLCA(struct Node*root,int n1,int n2)
{
    if(root==NULL)
        return NULL;
    
    if(root->data ==n1 || root->data ==n2)
        return root;
    
    struct Node*left_lca=findLCA(root->lc,n1,n2);
    struct Node*right_lca=findLCA(root->rc,n1,n2);

    if(left_lca && right_lca) return root;
    return (left_lca!=NULL)?left_lca:right_lca;
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
    printf("%d\n",findLCA(root,4,5)->data);
    printf("%d\n",findLCA(root,4,6)->data);
    printf("%d\n",findLCA(root,3,4)->data);
    printf("%d\n",findLCA(root,2,5)->data);
    return 0;
    
}