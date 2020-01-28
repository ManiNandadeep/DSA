#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
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
    Rquicksort(arr,0,n-1);
    int value=func(arr,0,n-1,x);
    printf("%d",value);
    return 0;
}
