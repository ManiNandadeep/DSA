#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int i,j,k;
    int arr[]={10,9,-8,7,6,5,4,3,-2,-1};
    int size=sizeof(arr)/sizeof(arr[0]);
    int max=-32767;
    for(i=0;i<size;i++)
    {
        for(j=i;j<size;j++)
        {
            int sum=0;
            for(k=i;k<j;k++)
                sum+=arr[k];
            if(sum>max)
            {
                max=sum;
            }
        }
    }
    printf("%d",max);
    return 0;
}