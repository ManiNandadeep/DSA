#include<stdio.h>
int binarysearch(int first,int last,int x,int arr[],int comparisions)
{
    int middle=(first+last)/2;
    if(first<=last)
    {
        if(arr[middle]==x)
        {
            comparisions++;
            printf("The element %d is found\n",x);
            printf("The number of comparisions is %d",comparisions)
            return 0;
        }
        else if(arr[middle]>x)
            binarysearch(first,middle-1,x,arr,comparisions+1);
        else
            binarysearch(middle+1,last,x,arr,comparisions+1);
    }
    else{
        printf("The number is not found");
        return -1;
    }
}
int main(void)
{
    int n,x;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d ",&arr[i]);
    scanf("%d",&x);
    // int first=0,last=n-1,middle;
    binarysearch(0,n-1,x,arr,0);
    return 0;
}