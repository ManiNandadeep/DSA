//stock market question
//O(n) time complexity
// to find the max value of arr[j]-arr[i] 
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int arr[]={13,18,100,3,99,10};
    int size=sizeof(arr)/sizeof(arr[0]);
    int i=0;
    int max=0;
    for(int j=1;j<size;j++)
    {
        if(arr[j]-arr[i]>max)
            max=arr[j]-arr[i];
        if(arr[i]>arr[j]) i=j;
    }
    printf("%d",max);
    return 0;
}