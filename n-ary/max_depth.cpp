#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    vector<Node*> child;
};
struct Node*newNode(int data)
{
    Node*tmp=new Node;
    tmp->data=data;
    return tmp;
}
int depthOfTree(struct Node*ptr)
{
    if(!ptr)
        return 0;
    int maxdepth=0;
    for(int i=0;i<ptr->child.size();i++)
    {
        maxdepth=max(maxdepth,depthOfTree(ptr->child[i]));
    }
    return maxdepth+1;
}
int main() 
{ 
   /*   Let us create below tree 
   *             A 
   *         / /  \  \ 
   *       B  F   D  E 
   *      / \    |  /|\ 
   *     K  J    G  C H I 
   *      /\            \ 
   *    N   M            L 
   */
  
   Node *root = newNode('A'); 
   (root->child).push_back(newNode('B')); 
   (root->child).push_back(newNode('F')); 
   (root->child).push_back(newNode('D')); 
   (root->child).push_back(newNode('E')); 
   (root->child[0]->child).push_back(newNode('K')); 
   (root->child[0]->child).push_back(newNode('J')); 
   (root->child[2]->child).push_back(newNode('G')); 
   (root->child[3]->child).push_back(newNode('C')); 
   (root->child[3]->child).push_back(newNode('H')); 
   (root->child[3]->child).push_back(newNode('I')); 
   (root->child[0]->child[0]->child).push_back(newNode('N')); 
   (root->child[0]->child[0]->child).push_back(newNode('M')); 
   (root->child[3]->child[2]->child).push_back(newNode('L')); 
  
   cout << depthOfTree(root) << endl; 
  
   return 0; 
} 