#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
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
void iter_in_ord(struct Node*node)
{
    if(node)
    {
        int top=-1;
        struct Node*S[100];
        bool B[100];
        S[++top]=node;
        B[top]=false;
        while(top>=0)
        {
            if(B[top]==true)
            { 
                printf("%d ",S[top--]->data);
            }
            else{
                node=S[top--];
                if(node->rc)
                {
                    S[++top]=node->rc;
                    B[top]=false;
                }
                S[++top]=node;
                B[top]=true;
                if(node->lc){
                    S[++top]=node->lc;
                    B[top]=false;
                }
            }
        }
    }
}
int main(void)
{
    // struct Node*root=newNode(10);
    // root->lc=newNode(8);
    // root->rc=newNode(2);
    // root->lc->lc=newNode(3);
    // root->lc->rc=newNode(5);
    // root->rc->lc=newNode(2);
    struct Node*root=newNode(1);
    root->lc=newNode(2);
    root->rc=newNode(3);
    root->lc->lc=newNode(4);
    root->lc->rc=newNode(5);
    root->rc->lc=newNode(6);
    root->rc->rc=newNode(7);
    iter_in_ord(root);
    return 0;
}