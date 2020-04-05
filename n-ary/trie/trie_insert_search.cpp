#include<bits/stdc++.h>
using namespace std;
const int ALPHA_SIZE=26;
struct TrieNode{
    struct TrieNode*children[ALPHA_SIZE];
    bool isEndOfWord;
};
struct TrieNode*newNode(void)
{
    struct TrieNode*tmp=new TrieNode;
    tmp->isEndOfWord=false;
    for(int i=0;i<ALPHA_SIZE;i++)
        tmp->children[i]=NULL;
    return tmp;
}
void insert(struct TrieNode*root,string key)
{
    struct TrieNode*pCrawl=root;
    for(int i=0;i<key.length();i++)
    {
        int index=key[i]-'a';
        if(!pCrawl->children[index])
            pCrawl->children[index]=newNode();
        pCrawl=pCrawl->children[index];
    }   
    pCrawl->isEndOfWord=true;
}
bool search(struct TrieNode*root,string key)
{
    struct TrieNode*pCrawl=root;
    for(int i=0;i<key.length();i++)
    {
        int index=key[i]-'a';
        if(!pCrawl->children[index])
            return false;
        pCrawl=pCrawl->children[index];
    }
    return (pCrawl!=NULL && pCrawl->isEndOfWord);
}

int main(void)
{
    string keys[]={"the","a","there","answer","any","by","bye","their"};
    int n=sizeof(keys)/sizeof(keys[0]);
    struct TrieNode*root=newNode();
    for(int i=0;i<n;i++)
        insert(root,keys[i]);
    search(root,"the")?cout<<"yes\n":cout<<"nope\n";
    search(root,"these")?cout<<"yes\n":cout<<"nope\n";
    return 0;
}