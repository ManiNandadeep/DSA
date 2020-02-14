//algorithm of complexitiy O(n^2)
#include<stdio.h>
#include<stdlib.h> 
int main(void)
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n-1;i++)
        scanf("%d ",&arr[i]);
    scanf("%d",&arr[n]);
    int min=32767;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(abs(arr[i]-arr[j])<min)
                min=abs(arr[i]-arr[j]);
        }
    }
    printf("%d",min);
    return 0;
}