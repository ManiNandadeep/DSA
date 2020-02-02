#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int A[]={694,563,784,321,653,893,151,792};
    int size=sizeof(A)/sizeof(A[0]);
    int max=10,i,d=3,b=1;
    int B[size];
    int C[max];
    while(d--)
    {
        for(i=0;i<max;i++)
            C[i]=0;
        for(i=0;i<size;i++)
            C[(A[i]/b)%10]++;
        for(i=1;i<max;i++)
            C[i]=C[i]+C[i-1];
        for(i=size-1;i>=0;i--)
            B[--C[(A[i]/b)%10]]=A[i];
        for(i=0;i<size;i++)
            A[i]=B[i];
        b=b*10;
    }
    for(i=0;i<size;i++)
        printf("%d ",A[i]);
    return 0;
}