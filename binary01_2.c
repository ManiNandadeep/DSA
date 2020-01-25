#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void BS(int arr[],int size,int no_zero,int first,int last)
{
    if(first<=last)
    {
        int mid=(first+last)/2;
        if(arr[mid]==size-mid-1-(no_zero-arr[mid]))
            printf("%d",mid);
        else if(arr[mid]<size-mid-1-(no_zero-arr[mid]))
            BS(arr,size,no_zero,mid+1,last);
        else
            BS(arr,size,no_zero,first,mid-1);       
    }
}
int main(void)
{
    char num[]="1000011";
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
    BS(arr,size,no_zero,0,size-1);
    return 0;
}