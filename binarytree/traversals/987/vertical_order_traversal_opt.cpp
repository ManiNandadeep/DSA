#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node*lc,*rc;
};
Node*newNode(int data)
{
    Node*tmp=new Node;
    tmp->data=data;
    tmp->lc=tmp->rc=NULL;
    return tmp;
}
void getVerticalOrder(Node*root,int hd,map<int,vector<int>> &m)
{
    if(root==NULL)
        return;
    m[hd].push_back(root->data);
    getVerticalOrder(root->lc,hd-1,m);
    getVerticalOrder(root->rc,hd+1,m);
}
void printVerticalOrder(Node*root)
{
    map<int,vector<int>>m;
    int hd=0;
    getVerticalOrder(root,hd,m);
    map<int,vector<int>>::iterator it;
    for(it=m.begin();it!=m.end();it++)
    {
        for(int i=0;i<it->second.size();i++)
            cout<< it->second[i]<<" ";
        cout<<endl;
    }
}
int main() 
{ 
    // Create binary tree shown in above figure 
    Node *root = newNode(1); 
    root->lc = newNode(2); 
    root->rc = newNode(3); 
    root->lc->lc = newNode(4); 
    root->lc->rc = newNode(5); 
    root->rc->lc = newNode(6); 
    root->rc->rc = newNode(7); 
    root->rc->lc->rc = newNode(8); 
    root->rc->rc->rc = newNode(9); 
  
    cout << "Vertical order traversal is \n"; 
    printVerticalOrder(root); 
  
    return 0; 
} 
