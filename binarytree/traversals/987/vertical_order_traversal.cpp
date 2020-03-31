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
//o(w*n) solution where w is the width of the binary tree

void findMinMax(Node*node,int &min,int &max,int hd)
{
    if(node==NULL)
        return ;
    if(hd<min) min=hd;
    else if (hd>max) max=hd;
    findMinMax(node->lc,min,max,hd-1);
    findMinMax(node->rc,min,max,hd+1);
}
void printVerticalLine(Node*node,int line_no,int hd)
{
    if(node==NULL)
        return ;
    if(hd==line_no)
        cout<<node->data<<" ";
    printVerticalLine(node->lc,line_no,hd-1);
    printVerticalLine(node->rc,line_no,hd+1);   
}
void verticalOrder(Node*root)
{
    int min=0,max=0;
    findMinMax(root,min,max,0);
    for(int line_no=min;line_no<=max;line_no++)
    {
        printVerticalLine(root,line_no,0);
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
    verticalOrder(root); 
  
    return 0; 
} 
