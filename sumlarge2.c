#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define swap(x,y) int t=x;x=y;y=t;
void mystrrev(char*num)
{
    for(int i=0;i<strlen(num)/2;i++)
    {
        swap(num[i],num[strlen(num)-1-i]);
    }
}
void strswap(char**num1,char**num2)
{
    char*temp=*num1;
    *num1=*num2;
    *num2=temp;
}
void findsum(char*num1,char*num2,int size1,int size2)
{
    int carry=0;
    char*result=malloc(255*sizeof(char));
    for(int i=0;i<size1;i++)
    {
        carry=carry+(num1[i]-'0')+(num2[i]-'0');
        result[i]=carry%10;
        carry=carry/10;
    }
    for(int i=size1;i<size2;i++)
    {
        carry=carry+(num2[i]-'0');
        result[i]=carry%10;
        carry=carry/10;
    }
    if(carry)
    {
        result[size2]=carry;
    }
    if(result[size2])
    {
        for(int i=size2;i>=0;i--)
        {
            printf("%d",result[i]);
        }
    }
    else{
        for(int i=size2-1;i>=0;i--)
        {
            printf("%d",result[i]);
        }
    }
}
int main(void)
{
    char*num1=malloc(255*sizeof(char));
    char*num2=malloc(255*sizeof(char));
    scanf("%s %s",num1,num2);
    if (strlen(num1)>strlen(num2))
    {
        strswap(&num1,&num2);
    }
    int size1=strlen(num1),size2=strlen(num2);
    mystrrev(num1);
    mystrrev(num2);
    findsum(num1,num2,size1,size2);
    free(num1);
    free(num2);
    return 0;

}