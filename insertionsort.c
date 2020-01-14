#include<stdio.h>
#define swap(x,y) int t=x;x=y;y=t;
void insertionsort(int arr[])
{
    for(int i=1;i<10;i++)
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
    int arr[10];
    for(int i=0;i<9;i++)
    {
        scanf("%d ",arr[i]);
    }
    scanf("%d",arr[9]);
    insertionsort(arr);
    for(int i=0;i<10;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0; 
}