#include<stdio.h>
#include<stdlib.h>
struct Node{
    char data;
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
    printf("%c",node->data);
    inorder(node->rc);
}
int Search(char arr[],int strt,int end,char value)
{
    int i;
    for(i=strt;i<=end;i++)
    {
        if (arr[i]==value)
        {
            return i;
        }
    }
}
struct Node*buildUtil(char in[],char post[],int inStrt,int inEnd,int*pIndex)
{
    if(inStrt>inEnd)
        return NULL;
    struct Node*node=newNode(post[*pIndex]);
    (*pIndex)--;
    if(inStrt==inEnd)
        return node;
    int iIndex=Search(in,inStrt,inEnd,node->data);
    node->rc=buildUtil(in,post,iIndex+1,inEnd,pIndex);
    node->lc=buildUtil(in,post,inStrt,iIndex-1,pIndex);
    return node;
}
struct Node*buildtree(char in[],char post[],int n)
{
    int pIndex=n-1;
    return buildUtil(in,post,0,n-1,&pIndex);
}
int main(void)
{
    char in[]={'D','B','E','A','F','C'};
    char post[]={'D','E','B','F','C','A'};
    int n=sizeof(in)/sizeof(in[0]);
    struct Node*root=buildtree(in,post,n);
    printf("inorder of the constructed tree:\n");
    inorder(root);
    return 0;
}