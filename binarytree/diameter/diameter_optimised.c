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
int diameter(struct Node*root,int*height)
{
    int lh=0,rh=0;
    int ldiameter=0,rdiameter=0;
    if(root==NULL)
    {
        *height=0;
        return 0;
    }
    ldiameter=diameter(root->lc,&lh);
    rdiameter=diameter(root->rc,&rh);
    
    *height=max(lh,rh)+1;
    return max(lh+rh+1,max(ldiameter,rdiameter));
}
int main(void)
{
    struct Node*root=newNode(1);
    root->lc=newNode(2);
    root->rc=newNode(3);
    root->lc->lc=newNode(4);
    root->lc->rc=newNode(5);
    int height=0;
    printf("Diameter of the given binary tree is %d\n",diameter(root,&height)-1);
    return 0;
}
