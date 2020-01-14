#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Node{
    int value;
    struct Node*next;
};
struct Node*head;
void reverse(struct Node**head)
{
   struct Node*pre=NULL;
   struct Node*next=NULL;
   struct Node*current=*head;
   while(current!=NULL)
   {
       next=current->next;
       current->next=pre;
       pre=current;
       current=next;
   } 
   *head=pre;
}
void insertatbeg(struct Node**head,int key)
{
    struct Node*newnode=malloc(sizeof(struct Node));
    newnode->value=key;
    newnode->next=*head;
    *head=newnode;
}
void print(void)
{
    struct Node*temp=head;
    while(temp!=NULL)
    {
        printf("%d",temp->value);
        printf("-->");
        temp=temp->next;
    }
    printf("NULL");
}
int main(void)
{
    
    insertatbeg(&head,1);
    insertatbeg(&head,2);
    insertatbeg(&head,3);
    insertatbeg(&head,4);
    insertatbeg(&head,5);
    print();
    reverse(&head);
    print();
    return 0;
}