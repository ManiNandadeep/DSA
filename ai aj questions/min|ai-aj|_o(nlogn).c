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
int main(void)
{
    int arr[]={20,18,11,15,13,1,9,7,9,4,17,19};
    int size=sizeof(arr)/sizeof(arr[0]);
    Rquicksort(arr,0,size-1);
    int min=32767;
    for(int i=1;i<size;i++)
    {
        if(abs(arr[i]-arr[i-1])<min)
            min=abs(arr[i]-arr[i-1]);
    }
    printf("%d",min);
    return 0;
}