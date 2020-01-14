#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    int data;
    struct Node*next;
};
void swapPointer(struct Node**a,struct Node**b)
{
    struct Node*t=*a;
    *a=*b;
    *b=t;
}
void push(struct Node**head,int new_data)
{
    struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->data=new_data;
    new_node->next=*head;
    *head=new_node;
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
int getSize(struct Node*node)
{
    int size=0;
    while(node!=NULL)
    {
        node=node->next;
        size++;
    }
    return size;
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
struct Node*make_empty_list(int size)
{
    struct Node*head=NULL;
    while(size--)
    {
        push(&head,0);
    }
    return head;
}
struct Node* multiply(struct Node*head1,struct Node*head2)
{
    int size1=getSize(head1);
    int size2=getSize(head2);
    if(size1<size2)
    {
        swapPointer(&head1,&head2);
    }
    reverse(&head1);
    reverse(&head2);
    struct Node*result=make_empty_list(size1+size2+1);
    struct Node*head2_ptr=head2,*result_ptr1=result,*result_ptr2,*head1_ptr;
    while(head2_ptr)
    {
        int carry=0;
        result_ptr2=result_ptr1;
        head1_ptr=head1;
        while(head1_ptr)
        {
            int mul=head1_ptr->data*head2_ptr->data+carry;
            result_ptr2->data+=mul%10;
            carry=mul/10+result_ptr2->data/10;
            result_ptr2->data=result_ptr2->data%10;
            head1_ptr=head1_ptr->next;
            result_ptr2=result_ptr2->next;
        }
        if(carry)
        {
            result_ptr2->data+=carry;
        }
        result_ptr1=result_ptr1->next;
        head2_ptr=head2_ptr->next;
    }
    reverse(&result);
    reverse(&head1);
    reverse(&head2);

    while(result->data==0)
    {
        struct Node*temp=result;
        result=result->next;
        free(temp);
    }
    return result;
}
int main(void)
{
    char*num1=malloc(255*sizeof(char));
    char*num2=malloc(255*sizeof(char));
    scanf("%s %s",num1,num2);
    struct Node*head1=NULL;
    struct Node*head2=NULL;
    int size1=strlen(num1),size2=strlen(num2);
    for(int i=size1-1;i>=0;i--)
        push(&head1,num1[i]-'0');
    for(int i=size2-1;i>=0;i--)
        push(&head2,num2[i]-'0');
    struct Node*result=multiply(head1,head2);
    printList(result);
   return 0;
}