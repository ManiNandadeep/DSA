#include<stdio.h>
#include<stdlib.h>
void printList(int arr[],int size)
{
    for(int i=0;i<size;i++)
        printf("%d ",arr[i]);
}
int merge(int arr[],int first,int mid,int last)
{
    int count=0;
    int arr1[last-first+1];
    int l=first,r=mid+1,p=0;
    while(l<=mid && r<=last)
    {
        if(arr[l]<=arr[r])
            arr1[p++]=arr[l++];
        else
        { 
            arr1[p++]=arr[r++];
            count+=mid-l+1;
        }
    }
    while(l<=mid) arr1[p++]=arr[l++];
    while(r<=last) arr1[p++]=arr[r++];
    p=0;
    l=first;
    while(l<=last) arr[l++]=arr1[p++];
    return count;
}
int mergesort(int arr[],int first,int last)
{
    int mid;
    if(first<last)
    {
        mid=(first+last)/2;
        return (mergesort(arr,first,mid)+mergesort(arr,mid+1,last)+merge(arr,first,mid,last));
    }
    return 0;
}
int main(void)
{
    int arr[]={10,9,11,8,12};
    int size=sizeof(arr)/sizeof(arr[0]);
    int count=mergesort(arr,0,size-1);
    printf("%d\n",count);
    printList(arr,size);
    return 0;
}