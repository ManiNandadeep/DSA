#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define swap(x,y) int t=x;x=y;y=t;
int partition(int arr[],int i,int j,int pivot)
{
    int l=i;
    int r=j;
    while(l<=r){
        while(l<=r && arr[l]<=pivot) 
            l++;
        while(l<=r && arr[r]>pivot) 
            r--;
        if(l<=r) {
            swap(arr[l],arr[r]);
            l++; r--;
        }
    }
    int k = l-1;
    swap(arr[i-1],arr[k]);
    arr[k] = pivot;
    return k;
}
void Rquicksort(int arr[],int i,int j)
{
    if(i<j)
    {
        int pivot_index=rand()%(j-i+1)+i;
        swap(arr[i],arr[pivot_index]);
        int k=partition(arr,i+1,j,arr[i]);
        Rquicksort(arr,i,k-1);
        Rquicksort(arr,k+1,j);
    }
}
int func(int arr[],int n)
{
    for(int k=0;k<n;k++)
    {
        int l=0,r=n-1;
        while(l<=r)
        {
            if(arr[l]+arr[r]==arr[k]) return true;
            else if(arr[l]+arr[r]<arr[k]) l++;
            else r--;
        }
    }
    return false;
}
int main(void)
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n-1;i++)
        scanf("%d ",&arr[i]);
    scanf("%d",&arr[n-1]);
    Rquicksort(arr,0,n-1);
    int value=func(arr,n);
    printf("%d",value);
    return 0;
}