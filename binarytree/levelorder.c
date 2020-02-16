#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 500
struct Node{
    int data;
    struct Node*lc;
    struct Node*rc;
};
struct Node**createQueue(int *front,int *rear)
{
    struct Node**queue=(struct Node**)malloc(sizeof(struct Node*)*MAX_SIZE);
    *front=*rear=0;
    return queue;
}
void enQueue(struct Node**queue,int *rear,struct Node*newnode)
{
    queue[*rear]=newnode;
    (*rear)++;
}
struct Node*deQueue(struct Node**queue,int *front)
{
    (*front)++;
    return queue[*front-1];
}
struct Node*newNode(int data)
{
    struct Node*node=(struct Node*)malloc(sizeof(struct Node));
    node->data=data;
    node->lc=NULL;
    node->rc=NULL;
    return node;
}
void printLevelOrder(struct Node*root)
{
    int rear,front;
    struct Node**queue=createQueue(&front,&rear);
    struct Node*temp_node=root;
    while(temp_node)
    {
        printf("%d",temp_node->data);
        if(temp_node->lc)
            enQueue(queue,&rear,temp_node->lc);
        if(temp_node->rc)
            enQueue(queue,&rear,temp_node->rc);
        temp_node=deQueue(queue,&front);
    }
}
int main(void)
{
    struct Node *root = newNode(1); 
    root->lc        = newNode(2); 
    root->rc       = newNode(3); 
    root->lc->lc  = newNode(4); 
    root->lc->rc = newNode(5); 

    printLevelOrder(root);
    return 0;
}