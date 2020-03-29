#include<bits/stdc++.h>
using namespace std;
struct Node{
    char key;
    vector<Node*>child;
};
Node*newNode(int key)
{
    Node*tmp=new Node;
    tmp->key=key;
    return tmp;
}
void traverse_tree(struct Node*root)
{
       stack<Node*> nodes;
       nodes.push(root);
       while(!nodes.empty())
       {
            Node*cur=nodes.top();
            nodes.pop();
            cout<< cur->key << "";
            for(int i=cur->child.size()-1;i>=0;i--)
            {
                nodes.push(cur->child[i]);
            }
       }
}
int main() 
{ 
    /*   Let us create below tree  
   *            A  
   *        /  / \  \  
   *       B  F   D  E  
   *      / \     |  /|\  
   *     K  J     G C H I  
   *    / \         |   |  
   *   N   M        O   L  
   */
  
    Node* root = newNode('A'); 
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
    (root->child[3]->child[0]->child).push_back(newNode('O')); 
    (root->child[3]->child[2]->child).push_back(newNode('L')); 
  
    traverse_tree(root); 
  
    return 0; 
} 
