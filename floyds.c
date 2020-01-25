#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node{
    int data;
    struct Node*next;
};
struct Node*head=NULL;
struct Node*head1=NULL;
void InsertAtBeg(struct Node**head,int key)
{
    struct Node*temp=malloc(sizeof(struct Node));
    temp->data=key;
    temp->next=*head;
    *head=temp;
}
void make_circular(struct Node*head1,int index)
{
    struct Node*temp=head1;
    struct Node*temp1=head1;
    while(temp->next !=NULL)
    {
        temp=temp->next;
    }
    for(int i=0;i<index;i++)
        temp1=temp1->next;
    temp->next=temp1;
}
bool floyds(struct Node*p1,struct Node*p2)
{
    while(p2!=NULL)
    {
        p1=p1->next;
        p2=p2->next;
        if(p2!=NULL)
            p2=p2->next;
        else
            return false;
        if(p1==p2)
            return true;
    }
    return false;
}
int main(void)
{
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int size=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size;i++)
        InsertAtBeg(&head,arr[i]);
    for(int i=0;i<9;i++)
        InsertAtBeg(&head1,arr[i]);
    make_circular(head1,5);
    struct Node*p1=malloc(sizeof(struct Node));
    struct Node*p2=malloc(sizeof(struct Node));
    p1=head1;
    p2=head1;
    bool b=floyds(p1,p2);
    printf("%d",b);
    return 0;
}