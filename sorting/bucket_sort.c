#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define p 10
#define swap(x,y) int t=x;x=y;y=t;
struct Node{
    int data;
    struct Node*next;
};
struct Node*B[p]={0};
void bubblesort(int arr[],int count)
{
    int i,j;
    for(i=0;i<count-1;i++)
    {
        for(j=0;j<count-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }        
    }
    for(int i=0;i<count;i++)
    {
        printf("%d ",arr[i]);
    }
}
int getSize(struct Node*node)
{
    int count=0;
    while(node!=NULL)
    {
        count++;
        node=node->next;
    }
    return count;
}
int getMax(int A[],int size)
{
    int max=A[0];
    for(int i=1;i<size;i++)
    {
        if(A[i]>max)
            max=A[i];
    }
    return max;
}
void InsertAtBeg(struct Node**head,int key)
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
        printf("%d ",node->data);
        node=node->next;
    }
    // printf("\n");
}
void BucketSort(int A[],int size,int count)
{
    for(int i=0;i<size;i++)
    {
        int index=A[i]/pow(10,count-1);
        InsertAtBeg(&B[index],A[i]);
    }
    for(int i=0;i<p;i++)
    {
        struct Node*head=B[i];
        struct Node*temp=head;
        int count=getSize(head);
        if(count==1)
            printList(B[i]);
        if(count>=2)
        {
            int arr[count];
            int i=0;
            while(temp!=NULL)
            {
                arr[i]=temp->data;
                i++;
                temp=temp->next;
            }
            bubblesort(arr,count);
        }
    }
}
int main(void)
{
    int A[]={654,321,312,153,152,143,765,985,976};
    int size=sizeof(A)/sizeof(A[0]);
    int max=getMax(A,size);
    int count=0;
    while(max)
    {
        count++;
        max=max/10;
    }
    BucketSort(A,size,count);
  
    return 0;
}