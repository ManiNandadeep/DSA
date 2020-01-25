#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
            l++; 
            r--;
        }
    }
    int k = l-1;
    swap(arr[i-1],arr[k]);
    arr[k] = pivot;
    return k;

}
int RFindRank(int arr[],int i,int j,int r)
{
    if(i<j)
    {
        int p=rand()%(j-i+1)+i;
        swap(arr[p],arr[i]);
        int k=partition(arr,i+1,j,arr[i]);
        if(r==j-k+1) return k;
        else if(r<j-k+1) RFindRank(arr,k+1,j,r);
        else RFindRank(arr,i,k-1,r-(j-k+1));
    }
}
int main(void)
{
    int arr[]={12,9,8,31,7,10,16,20,11,14};
    int size=sizeof(arr)/sizeof(arr[0]);
    int i=0,j=size-1,r;
    scanf("%d",&r);
    int index=RFindRank(arr,i,j,r);
    printf("%d",arr[index]);
}