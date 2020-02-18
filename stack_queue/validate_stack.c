#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool validateStack(int pushed[],int pushedsize,int popped[],int poppedsize)
{
    int Stack[1000];
    int top=-1;
    int j=0;
    for(int i=0;i<pushedsize;i++)
    {
        Stack[++top]=pushed[i];
        while (Stack[top]==popped[j] && top>=0)
        {
            j++;
            top--;   
        }
    }
    return top==-1;
}
int main(void)
{
    int pushed[]={1,2,3,4,5};
    int popped[]={4,5,3,1,2};
    int pushedsize=sizeof(pushed)/sizeof(pushed[0]);
    int poppedsize=sizeof(popped)/sizeof(popped[0]);
    printf("%d",validateStack(pushed,pushedsize,popped,poppedsize));
    return 0;
}