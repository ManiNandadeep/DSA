#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define swap(x,y) int t=x;x=y;y=t;
void strswap(char** num1,char** num2)
{
    char*temp=*num1;
    *num1=*num2;
    *num2=temp;
}
void mystrrev(char*num)
{
    for(int i=0;i<strlen(num)/2;i++)
    {
        swap(num[i],num[strlen(num)-i-1]);
    }
}
void append(char c,char*num,int size)
{
    num[size]=c;
}
void add(int *n1,int *n2,int no_grp1,int no_grp2)
{
    int carry=0;
    int *result=malloc(255*sizeof(char));
    for(int i=0;i<no_grp1;i++)
    {
        carry=carry+n1[i]+n2[i];
        result[i]=carry%10000;
        carry=carry/10000;
    }
    for(int i=no_grp1;i<no_grp2;i++)
    {
        carry=carry+n2[i];
        result[i]=carry%10000;
        carry=carry/10000;
    }
    if(carry)
    {
        result[no_grp2]=carry;
    }
    if (result[no_grp2])
    {
        for(int i=no_grp2;i>=0;i--)
        {
            printf("%d",result[i]);
        }
    }
    else{
        for(int i=no_grp2-1;i>=0;i--)
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
    printf("%s %s\n",num1,num2);
    while(size1%4!=0)
    {
        append('0',num1,size1);
        size1++;
    }
    while(size2%4!=0)
    {
        append('0',num2,size2);
        size2++;
    }
    printf("%s %s\n",num1,num2);
    mystrrev(num1);
    mystrrev(num2);
    printf("%s %s\n",num1,num2);
    int no_grp1=size1/4,no_grp2=size2/4;
    int *n1=malloc(no_grp1*sizeof(char));
    int *n2=malloc(no_grp2*sizeof(char));
    for(int i=0;i<no_grp1;i++)
    {
        for(int j=4*i;j<4*(i+1);j++)
        {
            n1[i]+=pow(10,j-4*i)*(num1[size1-1-j]-'0');
        }
    }
    for(int i=0;i<no_grp2;i++)
    {
        for(int j=4*i;j<4*(i+1);j++)
        {
            n2[i]+=pow(10,j-4*i)*(num2[size2-j-1]-'0');
        }
    }
    add(n1,n2,no_grp1,no_grp2);
    free(num1);
    free(num2);
    return 0;
}