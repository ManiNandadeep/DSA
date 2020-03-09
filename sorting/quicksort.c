/*This is also known as Hoare's partition scheme*/
/*author @ManiNandadeep*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define swap(x,y) int t;t=x;x=y;y=t;
void printsorted(int*arr,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
int partition(int*arr,int l,int h)
{
    int pivot=arr[l];
    int i=l-1;
    int j=h+1;
    while(true){
        do{
            i++;
        }while(arr[i]<pivot);
        do{
            j--;
        }while(arr[j]>pivot);
        if(i>=j)
            return j;
        swap(arr[i],arr[j]);
    }
}
int partition_r(int*arr,int l,int h)
{
    int r=rand()%(h-l+1)+l;
    swap(arr[r],arr[l]);
    return partition(arr,l,h);
}
void quicksort(int*arr,int l,int h)
{
    if(l<h)
    {
        int pivot_index=partition_r(arr,l,h);
        quicksort(arr,l,pivot_index-1);
        quicksort(arr,pivot_index+1,h);   
    }
}
int main(void)
{
    int i,n;
    scanf("%d\n",&n);
    int*arr=malloc(n*sizeof(char));
    scanf("%d",&arr[0]);
    for(i=1;i<n;i++)
        scanf(",%d",&arr[i]);
    quicksort(arr,0,n-1);
    printsorted(arr,n);
    return 0;
}