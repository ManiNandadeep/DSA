#include<stdio.h>
#define swap(x,y) int t=x;x=y;y=t;
void selectionsort(int arr[])
{
    int i,j,min,swappings=0,comparisions=0;
    for(int i=0;i<19;i++)
    {
        min=i;
        for(j=i+1;j<=19-i;j++)
        {
            comparisions++;
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
        swap(arr[i],arr[min]);
        swappings++;
    }
    for(int i=0;i<20;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n%d %d",swappings,comparisions);
}
int main(void)
{
    // int arr[20];
    // for(int i=0;i<19;i++)
    //     scanf("%d ",&arr[i]);
    // scanf("%d",&arr[19]);
    int arr[]={20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    selectionsort(arr);
    return 0;
}