#include<stdio.h>
#include<stdlib.h>
int max(int a,int b)
{
    if(a<b)
        return b;
    return a;
}
int min(int a,int b)
{
    if(a<b)
        return a;
    return b;
}
int trap(int arr[],int size)
{
    int i,sum=0;
    int*maxleft=malloc(size*sizeof(int));
    int*maxright=malloc(size*sizeof(int));
    maxright[size-1]=arr[size-1];
    maxleft[0]=arr[0];
    for(i=1;i<size;i++)
    {
        maxleft[i]=max(arr[i],maxleft[i-1]);
    }
    for(i=size-2;i>=0;i--)
    {
        maxright[i]=max(arr[i],maxright[i+1]);
    }
    for(i=0;i<size;i++)
    {
        sum+=(min(maxleft[i],maxright[i])-arr[i]);
    }
    return sum;
}
int main(void)
{
    // int arr[]={};
    // int size=sizeof(arr)/sizeof(arr[0]);
    int size;
    scanf("%d",&size);
    int *arr=malloc(size*sizeof(int));
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    int ans=trap(arr,size);
    printf("%d",ans);
    return 0;
}