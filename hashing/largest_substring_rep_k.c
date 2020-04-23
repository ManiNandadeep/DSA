#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define p 997
#define MAX 100000
struct Node{
    int data,count;
    struct Node*next;
};
struct Node*hashArray[p]={0};
int hashValue(int key)
{
    return key%p;
}
void InsertAtBeg(struct Node**head,int key,int freq)
{
    struct Node*temp=malloc(sizeof(struct Node));
    temp->data=key;
    temp->count=freq;
    temp->next=*head;
    *head=temp;    
}
bool confirm(char*str,int i,int j,int l)
{
    for(int a=0;a<l;a++)
    {
        if(str[i++]!=str[j++])
            return false;
    }
    return true;
}
bool check(char*str,int l,int k)
{
    int T=str[0]-'0',x=2;
    int bool_check;
    for(int j=1;j<l;j++)
    {
        x=hashValue(x*2);
        T=hashValue(T*2+(str[j]-'0'));
    }
    InsertAtBeg(&hashArray[T],0,1);
    for(int i=1;i<=strlen(str)-l;i++)
    {
        T=hashValue(T*2+(str[i+l-1]-'0')-x*(str[i-1]-'0'));
        if(T<0)
            T+=p;
        struct Node*temp=hashArray[T];
        int flag=0;
        while(temp!=NULL)
        {
            if(confirm(str,i,temp->data,l))
            {
                flag=1;
                temp->count++;
                if(temp->count == k)
                    return true;
            }
            // else
            // {
            //     InsertAtBeg(&hashArray[T],i,1);
            // }
            temp=temp->next;
            
        }
        if(flag==0)
        {
            InsertAtBeg(&hashArray[T],i,l);
        }
    }
    return false;    
}
int BS(int i,int j,char*str,int k,int*ans)
{
    int l;
    if(i<j)
    {
        l=(i+j)/2;
        if(check(str,l,k)==true) 
        {
            if(l>*ans) *ans=l;
            BS(l+1,j,str,k,ans);
        }
        else BS(i,l-1,str,k,ans);
    }
    return *ans;
}
int main(void)
{
    char*str=(char*)malloc(sizeof(int)*MAX);
    scanf("%s",str);
    int k;
    scanf("%d",&k);
    int ans=0;
    printf("%d",BS(1,strlen(str),str,k,&ans));
    return 0;
}