#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define N 5
int ptr[500];
void findSmallestRange(int arr[][N],int n,int k)
{
    int i,minval,maxval,minrange,minel,maxel,flag,minind;
    for(int i=0;i<=k;i++)
        ptr[i]=0;
    minrange=INT_MAX;
    while(1)
    {
        minind=-1;
        minval=INT_MAX;
        maxval=INT_MIN;
        flag=0;
        for(i=0;i<k;i++)
        {
            //if every element of list[i] is traversed then break the loop
            if(ptr[i]==n){
                flag=1;
                break;
            }
            if(ptr[i]<n && arr[i][ptr[i]]<minval)
            {
                minind=i;
                minval=arr[i][ptr[i]];
            }
            if(ptr[i]<n && arr[i][ptr[i]]>maxval)
            {
                maxval=arr[i][ptr[i]];
            }
        }
        if(flag) break;
        ptr[minind]++;
        if((maxval-minval)<minrange){
            minel=minval;
            maxel=maxval;
            minrange=maxel-minel;
        }
    }
    printf("the smallest range is [%d,%d]\n",minel,maxel);
}
int main(void)
{
    int arr[][N]={{4,7,9,12,15},{0,8,10,14,20},{6,12,16,30,50}};
    int k=sizeof(arr)/sizeof(arr[0]);
    findSmallestRange(arr,N,k);
    return 0;
}