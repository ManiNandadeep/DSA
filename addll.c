#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    int data;
    struct Node*next;
};
struct Node*result;
void strswap(char**num1,char**num2)
{
  char*temp=*num1;
    *num1=*num2;
    *num2=temp;
}
void insertatbeg(struct Node**head,int key)
{
    struct Node*temp=malloc(sizeof(struct Node));
    temp->data=key;
    temp->next=*head;
    *head=temp;
}
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
void printList(struct Node*node)
{
    while(node!=NULL)
    {
        printf("%d",node->data);
        node=node->next;
    }
    printf("\n");
}
struct Node*make_empty_list(int size)
{
    struct Node*head=NULL;
    while(size--)
    {
        insertatbeg(&head,0);
    }
    return head;
}
void add(struct Node *head1,struct Node*head2,int size1)
{
    result=make_empty_list(size1);
    struct Node*first=head1;
    struct Node*second=head2;
    struct Node*sum=result;
    int carry=0;
    while(second!=NULL)
    {
        carry=carry+first->data+second->data;
        sum->data+=carry%10;
        carry=carry/10;
        first=first->next;
        second=second->next;
        sum=sum->next;
    }
    while(first!=NULL)
    {
        carry=carry+first->data;
        sum->data+=carry%10;
        carry=carry/10;
        first=first->next;
        sum=sum->next;
    }
    if(carry)
    {
        insertatbeg(&result,carry);
    }

}
int main(void)
{
    struct Node*head1=NULL;
    struct Node*head2=NULL;
    // struct Node*result=NULL;
    char*num1=malloc(255*sizeof(char));
    char*num2=malloc(255*sizeof(char));
    scanf("%s %s",num1,num2);
    if(strlen(num1)<strlen(num2))
    {
        strswap(&num1,&num2);
    }
    int size1=strlen(num1),size2=strlen(num2);
    for(int i=size1-1;i>=0;i--)
        insertatbeg(&head1,num1[i]-'0');
    for(int i=size2-1;i>=0;i--)
        insertatbeg(&head2,num2[i]-'0');
    reverse(&head1);
    reverse(&head2);
    printList(head1);
    printList(head2);
    add(head1,head2,size1);
    reverse(&result);
    printList(result);
    return 0;
}