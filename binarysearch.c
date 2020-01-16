#include<stdio.h>
int main(void)
{
    int arr[11],i,count=0;  //count=number of comparisions
    for(i=0;i<10;i++)
        scanf("%d ",&arr[i]);
    scanf("%d",&arr[10]);
    int first=0,last=9,middle;
    while(first<=last)
    {
        middle=(first+last)/2;
        if(arr[10]==arr[middle])
        {
            count++;
            printf("The number %d is present",arr[10]);
            printf("\nThe number of comparisions is %d",count);
            break;
        }
        else if(arr[middle]>arr[10])
        {
            count++;
            last=middle-1;
        }
        else
        {
            count++;
            first=middle+1;
        }
        
    }
    if(first>last)
    {
        printf("The number %d is not found",arr[10]);
        printf("\nThe number of comparisions is %d",count);
    }
    return 0;
}