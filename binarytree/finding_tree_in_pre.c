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
struct Node*buildTree(char in[],char pre[],int inStrt,int inEnd)
{
    static int preIndex=0;
    if(inStrt>inEnd)
        return NULL;
    struct Node*tNode=newNode(pre[preIndex++]);
    if(inStrt==inEnd)
        return tNode;
    int inIndex=Search(in,inStrt,inEnd,tNode->data);
    tNode->lc=buildTree(in,pre,inStrt,inIndex-1);
    tNode->rc=buildTree(in,pre,inIndex+1,inEnd);
    return tNode;
}
int main(void)
{
    char in[]={'D','B','E','A','F','C'};
    char pre[]={'A','B','D','E','C','F'};
    int len=sizeof(in)/sizeof(in[0]);
    struct Node*root=buildTree(in,pre,0,len-1);
    printf("The inorder traversal of the binary tree is \n");
    inorder(root);
    return 0;
}