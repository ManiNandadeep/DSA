#include<stdio.h>
#include<stdlib.h>
#define max 10000
void Build(int A[],int ST[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        ST[n+i-1]=i;
    }
    for(i=n-2;i>-1;i--)
    {
        if (A[ST[2*i+1]]>A[ST[2*i+2]]) 
        {
            ST[i]=ST[2*i+2];
        }
        else 
        {
            ST[i]=ST[2*i+1];
        }
    }
}
void update(int ST[],int A[],int i,int X,int n)
{
    A[i]=X;
    int index=((n-1+i)-1)/2;
    while(index>0)
    {
        if(A[ST[2*index+1]]>A[ST[2*index+2]]) 
        {
            ST[index]=ST[2*index+2];
        }
        else 
        {
            ST[index]=ST[2*index+1];
        }
        index=(index-1)/2;
    }
    ST[0]=A[ST[1]]>A[ST[2]] ? ST[2]:ST[1];
}
int RMQ(int A[],int ST[],int i,int j,int s,int e,int p,int n)
{
    if(j<s || i>e)
    {  
        return n;
    }
    if(i<=s && e<=j)
    { 
        return ST[p];
    }
    int m=(s+e)/2;
    
    int l1=RMQ(A,ST,i,j,s,m,2*p+1,n);
    int l2=RMQ(A,ST,i,j,m+1,e,2*p+2,n);
    if (A[l1]<A[l2]) 
        return l1;
    else 
        return l2;
}

void RangeMinQuery(int A[],int ST[],int i,int j,int n)
{
    printf("\n%d",RMQ(A,ST,i,j,0,n-1,0,n));
}

int main(void)
{
    int n;
    scanf("%d",&n);
    int* A=malloc(sizeof(int)*n);
    // int A[]={1,3,2,7,9,11};
    // int n=sizeof(A)/sizeof(A[0]);
    // printf("%d\n",n);
    int*ST=malloc(sizeof(int)*(2*n-1));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    Build(A,ST,n);
    for(int i=0;i<2*n-1;i++)
        printf("%d ",ST[i]);
    RangeMinQuery(A,ST,1,5,n);
   // printf("\n%d",RMQ(A,ST,1,5,0,n-1,0,n));
    return 0;

}