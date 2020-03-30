#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node*lc,*rc;
};
struct Node*newNode(int data)
{
    Node*tmp=new Node;
    tmp->data=data;
    tmp->lc=tmp->rc=NULL;
    return tmp;
}
int findMaxUtil(Node*root,int &res)
{
    if(root==NULL)
        return 0;
    int left=max(0,findMaxUtil(root->lc,res));
    int right=max(0,findMaxUtil(root->rc,res));
    res=max(res,left+right+root->data);
    return max(left,right)+root->data;
}
int findMaxSum(Node*root)
{
    int res=INT_MIN;
    findMaxUtil(root,res);
    return res;
}
int main(void)
{
    // struct Node*root=newNode(10);
    // root->lc=newNode(2);
    // root->rc=newNode(10);
    // root->lc->lc=newNode(20);
    // root->lc->rc=newNode(1);
    // root->rc->rc=newNode(-25);
    // root->rc->rc->lc=newNode(3);
    // root->rc->rc->rc=newNode(4);
    struct Node*root=newNode(-10);
    root->lc=newNode(9);
    root->rc=newNode(20);
    root->rc->lc=newNode(15);
    root->rc->rc=newNode(7);
    cout<<"Max path sum is "<<findMaxSum(root);
    return 0;
}