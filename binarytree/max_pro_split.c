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
int max(int a,int b)
{
    if(a>b) return a;
    return b;
}
void dfs(struct Node*root,int *sum)
{
    if(root==NULL)
        return ;
    *sum+=root->data;
    dfs(root->lc,sum);
    dfs(root->rc,sum);   
}
int findmax(struct Node*root,int*ans,int sum)
{
    if(root==NULL)
        return 0;
    int s=root->data+findmax(root->lc,ans,sum)+findmax(root->rc,ans,sum);
    *ans=max(*ans,s*(sum-s));
    return s;
}
int maxproduct(struct Node*root)
{
    int ans=0;
    int sum=0;
    dfs(root,&sum);
    findmax(root,&ans,sum);
    return ans;
}
int main(void)
{
    struct Node*root=newNode(1);
    root->lc=newNode(2);
    root->lc->lc=newNode(4);
    root->lc->rc=newNode(5);
    root->rc=newNode(3);
    root->rc->lc=newNode(6);
    printf("%d",maxproduct(root));
    return 0;
}