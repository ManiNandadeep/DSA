#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void swap(char *x,char *y)
{
    char temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
void permute(char*a,int l,int r)
{
    if(l==r)
    {
        printf("%s\n",a);
    }
    else
    {
        for(int i=l;i<=r;i++)
        {
            swap((a+l),(a+r));
            permute(a,l+1,r);
            swap((a+l),(a+i));  //backtracking
        }
    }
}
int main(void)
{
    char*str=malloc(255*sizeof(char));
    scanf("%s",str);
    int n=strlen(str);
    permute(str,0,n-1);
    return 0;
}