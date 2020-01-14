#include<stdio.h>
#include<string.h>
#include<stdlib.h>
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
void push(struct Node**head,int key)
{
    struct Node*temp=malloc(sizeof(struct Node));
    temp->data=key;
    temp->next=*head;
    *head=temp;
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
struct Node* addSamesize(struct Node*head1,struct Node*head2,int *carry)
{
    if(head1==NULL)
        return NULL;
    int sum;
    struct Node*result=malloc(sizeof(struct Node));
    result->next=addSamesize(head1->next,head2->next,carry);
    sum = head1->data + head2->data + *carry; 
    *carry = sum / 10; 
    sum = sum % 10;  
    result->data = sum;
    return result;
}
void addCarryToRemaining(struct Node*head1,struct Node*cur,int *carry,struct Node**result)
{
    int sum;
    if(head1!=cur)
    {
        addCarryToRemaining(head1->next,cur,carry,result);
        sum=head1->data+*carry;
        *carry=sum/10;
        sum%=10;
        push(result,sum);
    }
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
void addList(struct Node*head1,struct Node*head2,struct Node**result)
{
    struct Node*cur;
    if(head1==NULL)
    {
        *result=head2;
        return ;
    }
    else if(head2==NULL)
    {
        *result=head1;
        return;
    }
    int size1=getSize(head1);
    int size2=getSize(head2);

    int carry=0;

    if(size1==size2)
    {
        *result=addSamesize(head1,head2,&carry);
    }
    else{
        int diff=abs(size1-size2);
        if(size1<size2)
            swapPointer(&head1,&head2);
        for(cur=head1;diff--;cur=cur->next);
        *result=addSamesize(cur,head2,&carry);
        addCarryToRemaining(head1,cur,&carry,result);
    }
    if(carry)
        push(result,carry);
}
int main(void)
{
    char*num1=malloc(255*sizeof(char));
    char*num2=malloc(255*sizeof(char));
    scanf("%s %s",num1,num2);
    struct Node*head1=NULL;
    struct Node*head2=NULL;
    struct Node*result=NULL;
    int size1=strlen(num1),size2=strlen(num2);
    for(int i=size1-1;i>=0;i--)
        push(&head1,num1[i]-'0');
    for(int i=size2-1;i>=0;i--)
        push(&head2,num2[i]-'0');
    addList(head1,head2,&result);
    printList(result);
    return 0;
}