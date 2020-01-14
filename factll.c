#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
struct Node{
    int data;
    struct Node*next;
};
struct Node*head=NULL;
void createnode(struct Node**head)
{
    struct Node*temp;
    temp->next=*head;
    *head=temp;
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
struct Node*make_empty_list(int size)
{
    struct Node*head=NULL;
    while(size--)
    {
        push(&head,0);
    }
    return head;
}
int multiply(int *result,int x,int res_size)
{
	int carry=0;
	for(int i=0;i<res_size;i++)
	{
		carry=carry+result[i]*x;
		result[i]=carry%10;
		carry=carry/10;
	}
	while(carry)
	{
		result[res_size]=carry%10;
		carry=carry/10;
		res_size++;
	}
	return res_size;
}
void factorial(struct Node*head)
{
	// int *result=malloc(10000*sizeof(char));
    struct Node*result=NULL;
	int res_size=1;
	result[0]=1;
	for(int x=2;x<=n;x++)
	{
		res_size=multiply(result,x,res_size);
	}
	for(int i=res_size-1;i>=0;i--)
	{
		printf("%d",result[i]);
	}
	free(result);
}
int main(void)
{
	clock_t start,end;
	double cpu_time_used;
	start=clock();
	char*num=malloc(255*sizeof(char));
	scanf("%s",num);
    for(int i=sizeof(num)-1;i>=0;i++)
    {
        push(&head,num[i]-'0');
    }
	factorial(&head);
	end=clock();
    free(num);
	cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
	printf("\n%lf",cpu_time_used);
	return 0;
}
