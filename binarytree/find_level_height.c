#include<stdio.h>
#include<stdlib.h>
#define MAX(a,b) (a>b ? a:b)
struct Node{
    int data,level,height;
    struct Node*lc;
    struct Node*rc;
    struct Node*parent;
};
struct Node*newNode(int key,struct Node*parent)
{
    struct Node*temp=malloc(sizeof(struct Node));
    temp->data=key;
    temp->lc=NULL;
    temp->rc=NULL;
    temp->parent=parent;
    return temp;
}
void find_level_pre(struct Node*node)
{
    if(node==NULL)
        return ;
    if(node->parent==NULL)
        node->level=0;
    else
        node->level=1+(node->parent)->level;
    printf("Level of %d is %d\n",node->data,node->level);
    find_level_pre(node->lc);
    find_level_pre(node->rc);
}
void find_height_post(struct Node *node)
{
    if(node==NULL)
        return ;
    if(node->lc==NULL && node->rc==NULL)
        node->height=0;
    else
        node->height=1+MAX(node->lc->height,node->rc->height);
    
    find_height_post(node->lc);
    find_height_post(node->rc);
    printf("Height of %d is %d\n",node->data,node->height);
}
int main(void)
{
    struct Node*root=newNode(1,NULL);
    root->lc=newNode(2,root);
    root->rc=newNode(3,root);
    root->lc->lc=newNode(4,root->lc);
    root->lc->rc=newNode(5,root->lc);
    root->rc->lc=newNode(6,root->rc);
    root->rc->rc=newNode(7,root->rc);

    find_level_pre(root);

    find_height_post(root);

    return 0;
}