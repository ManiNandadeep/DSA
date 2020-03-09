#include<stdio.h>
#define swap(x,y) int t=x;x=y;y=t;
void bubblesort(int arr[])
{
    int i,j,swappings=0,comparisions=0;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9-i;j++)
        {
            comparisions++;
            if(arr[j]>arr[j+1])
            {
                swappings++;
                swap(arr[j],arr[j+1]);
            }
        }
        
    }
    for(int i=0;i<10;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n%d %d\n",swappings,comparisions);
}
int main(void)
{
    int arr[10];
    for(int i=0;i<9;i++)
    {
        scanf("%d ",&arr[i]);
    }
    scanf("%d",&arr[9]);
    bubblesort(arr);
     for(int i=0;i<10;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}