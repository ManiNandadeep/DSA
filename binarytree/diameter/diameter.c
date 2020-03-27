/* 
    time complexity-o(n)
    can we do better?
*/
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*lc,*rc;
};
struct Node*newNode(int data)
{
    struct Node*tmp=(struct Node*)malloc(sizeof(struct Node));
    tmp->data=data;
    tmp->lc=tmp->rc=NULL;
    return tmp;
}
int max(int a,int b)
{
    if(a>b) return a;
    return b;
}
int height(struct Node*node)
{
    if(node==NULL)
        return 0;
    return 1+max(height(node->lc),height(node->rc));
}
int diameter(struct Node*tree)
{
    if(tree==NULL)
        return 0;
    int lheight=height(tree->lc);
    int rheight=height(tree->rc);

    int ldiameter=diameter(tree->lc);
    int rdiameter=diameter(tree->rc);
    return max(lheight+rheight+1,max(ldiameter,rdiameter));
}
int main(void)
{
    struct Node*root=newNode(1);
    root->lc=newNode(2);
    root->rc=newNode(3);
    root->lc->lc=newNode(4);
    root->lc->rc=newNode(5);
    printf("Diameter of the given binary tree is %d\n",diameter(root));
    return 0;
}
