#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node*left,*right;
};
Node*newNode(int data)
{
    Node*tmp=new Node();
    tmp->data=data;
    tmp->left=tmp->right=NULL;
    return tmp;
}
void Inorder(Node*root)
{
    if(root==NULL)
        return;
    Inorder(root->left);
    cout<< root->data<<" ";
    Inorder(root->right);
}
Node*createBST(int*mergedarr,int l,int r)
{
    if(l>r||l<0)
        return NULL;
    int m=(l+r)/2;
    Node*root=newNode(mergedarr[m]);
    root->left=createBST(mergedarr,l,m-1);
    root->right=createBST(mergedarr,m+1,r);
    return root;
}
int*merge(int arr1[],int arr2[],int m,int n)
{
    int*mergedarr=new int[m+n];
    int i=0,j=0,k=0;
    while(i<m && j<n)
    {
        if(arr1[i]<arr2[j])
        {
            mergedarr[k++]=arr1[i++];
        }
        else{
            mergedarr[k++]=arr2[j++];
        }
    }
    while(i<m)
    {
        mergedarr[k++]=arr1[i++];
    }
    while(j<n)
    {
        mergedarr[k++]=arr2[j++];
    }
    return mergedarr;
}
void store(Node*root,int*arr,int*index)
{
    if(root==NULL)
        return;
    store(root->left,arr,index);
    arr[(*index)++]=root->data;
    store(root->right,arr,index);
}
Node*mergetrees(Node*root1,Node*root2,int m,int n)
{
    int*arr1=new int[m];
    int*arr2=new int[n];
    int i=0,j=0;
    store(root1,arr1,&i);
    store(root2,arr2,&j);
    int*mergedarr=merge(arr1,arr2,m,n);
    return createBST(mergedarr,0,m+n-1);
}
int find_size(Node*root)
{
    if(!root) return 0;
    return 1+find_size(root->left)+find_size(root->right);
}
int main(void)
{
    Node *root1 = newNode(100);  
    root1->left     = newNode(50);  
    root1->right = newNode(300);  
    root1->left->left = newNode(20);  
    root1->left->right = newNode(70); 
    
    Node *root2 = newNode(80);  
    root2->left     = newNode(40);  
    root2->right = newNode(120);

    int size1=find_size(root1);
    int size2=find_size(root2);
    Node*mergedtree=mergetrees(root1,root2,size1,size2);
    Inorder(mergedtree);
    return 0;
}