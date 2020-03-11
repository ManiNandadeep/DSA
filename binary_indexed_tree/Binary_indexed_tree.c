#include<stdio.h>
#include<stdlib.h>
int PS(int BIT[],int i)
{
    int sum=0;
    i++;
    while(i>0)
    {
        sum+=BIT[i];
        i-=i&(-i);
    }
    return sum;
}
void updateBIT(int BIT[],int n,int index,int val)
{
    index+=1;
    while(index<=n)
    {
        BIT[index]+=val;
        index+=index&(-index);
    }
}
int* Build_Indexed_tree(int A[],int n)
{
    int*BIT=malloc(sizeof(int)*(n+1));
    for(int i=0;i<=n;i++)
    {
        BIT[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        updateBIT(BIT,n,i,A[i]);
    }
    return BIT;
}
int main(void)
{
    int n;
    scanf("%d",&n);
    int *A=malloc(sizeof(int)*(n));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    int *BIT=Build_Indexed_tree(A,n);
    printf("%d\n",PS(BIT,5));
    return 0;
}