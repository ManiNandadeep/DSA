//to calculate the number of inversion pairs (if i<j then a[i]>a[j]) in O(n^2)
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int arr[]={10,9,8,7,6,5,4,3,2,1};
    int size=sizeof(arr)/sizeof(arr[0]);
    int i,j,count=0;
    for(i=0;i<size;i++)
    {
        for(j=i+1;j<size;j++)
        {
            if(arr[i]>arr[j])
                count++;
        }
    }
    printf("%d",count);
    return 0;    
}