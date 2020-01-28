#include<stdio.h>
#include<stdbool.h>
bool func(int arr[],int l,int r,int x)
{
    while(l<=r)
    {
        if(arr[l]+arr[r]==x) return true;
        else if(arr[l]+arr[r]<x) l++;
        else r--; 
    }
    return false;
}
int main(void)
{
    int n,x;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d ",&arr[i]);
    scanf("%d",&x);
    int value=func(arr,0,n-1,x);
    printf("%d",value);
    return 0;
}