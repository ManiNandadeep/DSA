#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void)
{
    char num[]="100001";
    int size=strlen(num);
    int arr[size];
    int counter=0;
    for(int i=0;i<size;i++)
    {
        if(num[i]=='0')
            counter++;
        arr[i]=counter;
        printf("%d ",arr[i]);
    }
    printf("\n");
    int no_zero=arr[size-1];
    int no_one=size-arr[size-1];
    printf("%d\n",no_one);
    for(int i=0;i<size;i++)
    {
        if(arr[i]==size-1-i-(no_zero-arr[i]))
            printf("%d",i);
    }
    return 0;
}