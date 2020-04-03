#include<bits/stdc++.h>
using namespace std;
struct node 
{ 
    int key; 
    struct node *left, *right; 
}; 
struct node *newNode(int item) 
{ 
    struct node *temp =  new node; 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
void preorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        cout << root->key << " "; 
        preorder(root->left); 
        preorder(root->right); 
    } 
} 
//code starts here------
vector<struct node*>constructTrees(int start,int end)
{
    vector<struct node*>list;
    if(start>end)
    {
        list.push_back(NULL);
        return list;
    }
    for(int i=start;i<=end;i++)
    {
        vector<struct node*>leftsubtree=constructTrees(start,i-1);
        vector<struct node*>rightsubtree=constructTrees(i+1,end);
        for(int j=0;j<leftsubtree.size();j++)
        {
            struct node*left=leftsubtree[j];
            for(int k=0;k<rightsubtree.size();k++)
            {
                struct node*right=rightsubtree[k];
                struct node*node=newNode(i);
                node->left=left;
                node->right=right;
                list.push_back(node);
            }
        }
    }
        return list;
}
//code ends here -------
int main() 
{ 
    // Construct all possible BSTs 
    vector<struct node *> totalTreesFrom1toN = constructTrees(1, 3); 
  
  
    /*  Printing preorder traversal of all constructed BSTs   */
    cout << "Preorder traversals of all constructed BSTs are \n"; 
    for (int i = 0; i < totalTreesFrom1toN.size(); i++) 
    { 
        preorder(totalTreesFrom1toN[i]); 
        cout << endl; 
    } 
    return 0; 
} 