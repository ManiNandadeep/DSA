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
void iterPreOrd(struct Node*node)
{
    if(node==NULL)
        return ;
    struct Node*S[100];
    if(node)
    {
        int top=-1;
        S[++top]=node;
        while(top>=0)
        {
            printf("%d ",S[top]->data);
            node=S[top--];
            if(node->rc) S[++top]=node->rc;
            if(node->lc) S[++top]=node->lc;     
        }
       
    }
}
int main(void)
{
    struct Node*root=newNode(10);
    root->lc=newNode(8);
    root->rc=newNode(2);
    root->lc->lc=newNode(3);
    root->lc->rc=newNode(5);
    root->rc->lc=newNode(2);
    iterPreOrd(root);
    return 0;
}
