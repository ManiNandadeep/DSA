#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int arr[]={-5,-6,-3,-2,-1};
    int size=sizeof(arr)/sizeof(arr[0]);
    int i,j,imax,jmax;
    int sum;
    int max=-32767;
    i=0;
    sum=0;
    for(j=i;j<size;j++)
    {
        sum+=arr[j];
        if(sum>max)
        {
            max=sum;
            imax=i+1;
            jmax=j;
        }
        if(sum<0)
        {
            sum=0;
            i=j;
        }
    }
    printf("%d",max);
    printf("\n%d %d",imax,jmax);
    return 0;
}