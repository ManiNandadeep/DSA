#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int arr[]={-5,-4,-3,-2,-1};
    int size=sizeof(arr)/sizeof(arr[0]);
    int sum=0;
    int j;
    int max=-32767;
    for(j=0;j<size;j++)
    {
        sum+=arr[j];
        if(sum>max)
            max=sum;
        if(sum<0)
            sum=0;
    }
    printf("%d",max);
    return 0;
}