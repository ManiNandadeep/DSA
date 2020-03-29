//using level order traversal 
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node*lc,*rc;
};
int maxWidth(struct Node*root)
{
    if(root==NULL)
        return 0;
    int result=0;
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        int count=q.size();
        result=max(count,result);
        while(count--)
        {
            Node*tmp=q.front();
            q.pop();
            if(tmp->lc!=NULL)
                q.push(tmp->lc);
            if(tmp->rc!=NULL)
                q.push(tmp->rc);
        }
    }
    return result;
}
struct Node*newNode(int data)
{
    struct Node*node=new Node;
    node->data=data;
    node->lc=node->rc=NULL;
    return node;
}
int main()
{
     struct Node *root = newNode(1); 
    root->lc        = newNode(2); 
    root->rc       = newNode(3); 
    root->lc->lc  = newNode(4); 
    root->lc->rc = newNode(5); 
    root->rc->rc = newNode(8); 
    root->rc->rc->lc  = newNode(6); 
    root->rc->rc->rc  = newNode(7); 
  
    /*   Constructed Binary tree is: 
                 1 
               /   \ 
             2      3 
           /  \      \ 
          4    5      8 
                    /   \ 
                   6     7    */
    cout << "Maximum width is "
         << maxWidth(root) << endl; 
    return 0; 

}