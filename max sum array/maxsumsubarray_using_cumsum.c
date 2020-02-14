#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(void)
{
    int arr[] ={10,-9,-8,-7,-6,5,4,3,2,1};
    int size=sizeof(arr)/sizeof(arr[0]);
    int p[size+1];
    p[0]=0;
    for(int i=1;i<=size;i++)
        p[i]=p[i-1]+arr[i-1];
    int i=0,j;
    int max=0;
    for(int j=1;j<=size;j++)
    {
        if(p[j]-p[i]>max)
            max=p[j]-p[i];
        if(p[i]>p[j]) i=j;
    }
    printf("%d",max);
    return 0;    
}