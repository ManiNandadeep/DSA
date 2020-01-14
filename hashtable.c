#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define p 997
struct Node{
    int data;
    struct Node*next;
};
struct Node*hashArray[p]={0};
int hashValue(int key)
{
    return key%p;
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
        printf("%d",node->data);
        node=node->next;
    }
    printf("\n");
}
void traverse(struct Node*node,char*text,char*pat,int n,int m)
{
    while(node!=NULL)
    {
        for(int i=node->data,k=0;k<m;k++)
        {
            if(text[i+k]!=pat[k])
            {
                break;
            }
        }    
        printf("There is a match at %d.\n",node->data);
        node=node->next;
    }
}
int main(void)
{
    char *text=malloc(255*sizeof(char));
    char *pat=malloc(255*sizeof(char));
    scanf("%s %s",text,pat);
    int n=strlen(text),m=strlen(pat);
    int T=text[0]-'0',P=pat[0]-'0',x=2;
    for(int j=1;j<m;j++)
    {
        x=hashValue(x*2);
        T=hashValue(T*2+(text[j]-'0'));
        P=hashValue(P*2+(pat[j]-'0'));
    }
    int required_hash=P;
    printf("%d\n",required_hash);
    printf("%d\n",T);
    InsertAtBeg(&hashArray[T],0);
    for(int i=1;i<=n-m;i++)
    {
        T=hashValue(T*2+(text[i+m-1]-'0')-x*(text[i-1]-'0'));
        InsertAtBeg(&hashArray[T],i);
    }
    printList(hashArray[required_hash]);
    traverse(hashArray[required_hash],text,pat,n,m);
    return 0;
}