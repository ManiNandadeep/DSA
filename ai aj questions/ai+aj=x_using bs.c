#include<stdio.h>
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
int BS(int arr[],int ele,int first,int last)
{
    int mid;
    if(first<=last)
    {
        mid=(first+last)/2;
        if(arr[mid]==ele) return mid;
        else if(arr[mid]>ele) return BS(arr,ele,first,mid-1);
        else return BS(arr,ele,mid+1,last);
    }
    else return -1;
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
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
    for(int i=0;i<n;i++)
    {
        int j=BS(arr,x-arr[i],0,n-1);
        printf("%d %d\n",arr[i],j);
    }
    return 0;
}