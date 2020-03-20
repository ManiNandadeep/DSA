#include<stdio.h>
#include<stdlib.h>
struct Node{
    int key;
    struct Node*lc,*rc;
};
struct Node*newnode(int item)
{
    struct Node*tmp=(struct Node*)malloc(sizeof(struct Node));
    tmp->key=item;
    tmp->lc= tmp->rc=NULL;
    return tmp;
}
struct Node*insert(struct Node*node,int key)
{
    if(node==NULL)  return newnode(key);
    if(key < node->key)
        node->lc=insert(node->lc,key);
    else if(key > node->key)
        node->rc=insert(node->rc,key);
    return node;
}
void storeSorted(struct Node*root,int arr[],int *i)
{
    if(root!=NULL)
    {
        storeSorted(root->lc,arr,i);
        arr[(*i)++]=root->key;
        storeSorted(root->rc,arr,i);
    }
}
void treesort(int arr[],int n)
{
    struct Node*root=NULL;
    root=insert(root,arr[0]);
    for (int i=1;i<n;i++)
    {
        insert(root,arr[i]);
    }
    int i=0;
    storeSorted(root,arr,&i);
}
int main(void)
{
    int arr[]={5,4,7,2,11};
    int n=sizeof(arr)/sizeof(arr[0]);
    treesort(arr,n);
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    return 0;
}