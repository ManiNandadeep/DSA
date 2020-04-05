#include<bits/stdc++.h>
using namespace std;
const int ALPHA_SET=26;
struct TrieNode{
    struct TrieNode*child[ALPHA_SET];
    bool isEndOfWord;
};
struct TrieNode*newNode(void)
{
    struct TrieNode*pnode=new TrieNode;
    pnode->isEndOfWord=false;
    for(int i=0;i<ALPHA_SET;i++)
        pnode->child[i]=NULL;
    return pnode;
}
void insert(struct TrieNode*root,string key)
{
    struct TrieNode*pcrawl=root;
    for(int i=0;i<key.length();i++)
    {
        int index=key[i]-'a';
        if(!pcrawl->child[index])
            pcrawl->child[index]=newNode();
        pcrawl=pcrawl->child[index];
    }
    pcrawl->isEndOfWord=true;
}
bool search(struct TrieNode* root, string key) 
{ 
    struct TrieNode* pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) { 
        int index = key[i] - 'a'; 
        if (!pCrawl->child[index]) 
            return false; 
  
        pCrawl = pCrawl->child[index]; 
    } 
  
    return (pCrawl != NULL && pCrawl->isEndOfWord); 
} 
bool isEmpty(TrieNode*root)
{
    for(int i=0;i<ALPHA_SET;i++)
    {
        if(root->child[i])
            return false;
    }
    return true;
}
TrieNode*remove(TrieNode*root,string key,int depth=0)
{
    if(!root)
        return NULL;
    if(depth==key.size())
    {
        if(root->isEndOfWord)
            root->isEndOfWord=false;
        if(isEmpty(root))
        {
            delete(root);
            root=NULL;
        }
        return root;
    }
    int index=key[depth]-'a';
    root->child[index]=remove(root->child[index],key,depth+1);
    if(isEmpty(root) && root->isEndOfWord==false)
    {
        delete(root);
        root=NULL;
    }
    return root;
}
int main(void)
{
    string keys[] = { "the", "a", "there", 
                      "answer", "any", "by", 
                      "bye", "their", "hero", "heroplane" }; 
    int n = sizeof(keys) / sizeof(keys[0]); 
  
    struct TrieNode* root = newNode(); 
  
    // Construct trie 
    for (int i = 0; i < n; i++) 
        insert(root, keys[i]); 
  
    // Search for different keys 
    search(root, "the") ? cout << "Yes\n" : cout << "No\n"; 
    search(root, "these") ? cout << "Yes\n" : cout << "No\n"; 
  
    remove(root, "heroplane"); 
    search(root, "hero") ? cout << "Yes\n" : cout << "No\n"; 
    return 0; 
}