#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int A[]={10,3,1,2,5,9,7,6,4,8,0,0};
    int size=sizeof(A)/sizeof(A[0]);
    int max=0;
    int*B=malloc(255*sizeof(char));
    int*C=malloc(255*sizeof(char));
    int i;
    for(i=0;i<size;i++)
    {
        if(A[i]>max)
            max=A[i];
    }
    for(i=0;i<=max;i++)
        C[i]=0;
    for(i=0;i<size;i++)
        C[A[i]]++;
    for(i=1;i<=max;i++)
        C[i]=C[i]+C[i-1];
    // for(i=0;i<=max;i++)
    //     printf("%d ",C[i]);
    for(i=size-1;i>=0;i--)
    {
        B[--C[A[i]]]=A[i];   
    }
    for(i=0;i<size;i++)
    {
        printf("%d ",B[i]);
    }   
    return 0;
}