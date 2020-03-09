#include<stdio.h>
#define swap(x,y) int t=x;x=y;y=t;
void insertionsort(int arr[])
{
    for(int i=1;i<20;i++)
    {
        int temp=arr[i];
        int j=i-1;
        while(j>=0&&arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=temp;
    }
}
int main(void)
{
    // int arr[20];
    // for(int i=0;i<19;i++)
    // {
    //     scanf("%d ",arr[i]);
    // }
    // scanf("%d",arr[19]);
    int arr[]={20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    insertionsort(arr);
    for(int i=0;i<20;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0; 
}