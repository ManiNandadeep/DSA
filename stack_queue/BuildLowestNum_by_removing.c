#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Stack
{
    char val;
    struct Stack *next;
};

struct Stack *Initialize()
{
    struct Stack *S = (struct Stack*)malloc(sizeof(struct Stack));
    S->next = NULL;
    return S;
}

void Push(struct Stack *S, char x)
{
    struct Stack *tmp = (struct Stack*)malloc(sizeof(struct Stack));
    tmp->val = x;
    tmp->next = S->next;
    S->next = tmp;
}

void Pop(struct Stack *S)
{
    struct Stack *tmp = S->next;
    S->next = tmp->next;
    tmp->next = NULL;
    free(tmp);
}

char Top(struct Stack *S)
{
    return S->next->val;
}

int IsEmpty(struct Stack *S)
{
    return S->next == NULL;
}

char* removeKdigits(char*num,int k)
{
    struct Stack*S=Initialize();

    for(int i=0;i<strlen(num);++i)
    {
        while(S->next !=NULL && num[i]< S->next->val && k>0)
        {
            Pop(S);
            k--;
        }
        if(num[i]!='0' || !IsEmpty(S))
        {
            Push(S,num[i]);
        }
    }
    while(!IsEmpty(S) && k>0)
    {
        Pop(S);
        k--;
    }
    struct Stack *pos=S->next;
    int len=0;
    while(pos)
    {
        len++;
        pos = pos->next;
    }
    if(len==0)
    {
        char*res=(char*)malloc(sizeof(char)*2);
        res[0]='0';
        res[1]='\0';
        return res;
    }
    char*result=(char*)malloc(sizeof(char)*(len+1));
    int i=len-1;
    while(S->next)
    {
        result[i]=Top(S);
        Pop(S);
        i--;
    }
    result[len]='\0';
    return result;
}


int main(void)
{
    char str[]="10200";
    int n=1;
    printf("%s",removeKdigits(str,n));
    return 0;
}   
