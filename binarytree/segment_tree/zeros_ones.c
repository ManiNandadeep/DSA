#include<stdio.h>
#include<stdlib.h>
int fill_zeros(int num)
{
    int power=1;
    while (num>0)
    {
        num=num/2;
        power*=2;
    }
    return power;
}
int KthOne(int ST[],int n,int k,int start,int end,int root)
{
    if(k>ST[root] || start<0 || end>n-1 )
        return -1;
    else if(k==ST[root] && start==end)
        return end;
    int mid=(start+end)/2;
    if(k>ST[2*root+1])
    {
        int right=KthOne(ST,n,k-ST[2*root+1],mid+1,end,2*root+2);
        return right;
    }
    else
    {
        int left=KthOne(ST,n,k,start,mid,2*root+1);
        return left;
    }
}
void UpdateST(int ST[],int n,int index)
{
    if(ST[n-1+index]==0)
        return ;
    ST[n-1+index]=0;
    int parent=((n-1+index)-1)/2;
    while (parent>0)
    {
        ST[parent]-=1;
        parent=(parent-1)/2;
    }
    ST[0]-=1;    
}
void BuildST(int ST[],int num,int n)
{
    for(int i=0;i<n;i++)
    {
        if(i<num)
            ST[n-1+i]=1;
        else
            ST[n-1+i]=0;
    }
    for(int i=n-2;i>-1;i--)
    {
        ST[i]=ST[2*i+1]+ST[2*i+2];
    }
}
int main(void)
{
    int num;
    scanf("%d",&num);
    int n=fill_zeros(num);
    int *ST=malloc(sizeof(int)*(4*n));
    BuildST(ST,num,n);
    int num_of_queries;
    scanf("%d",&num_of_queries);
    int *queries=malloc(sizeof(int)*num_of_queries);
    int *indexes=malloc(sizeof(int)*num_of_queries);
    for(int i=0;i<num_of_queries;i++)
    {
        scanf("%d %d",queries+i,indexes+i);
    }
    for(int i=0;i<num_of_queries;i++)
    {
        if(queries[i]==0)
        {
            UpdateST(ST,n,indexes[i]-1);
        }
        else if(queries[i]==1)
        {
            int index=KthOne(ST,n,indexes[i],0,n-1,0);
            if(index!=-1)
                printf("%d\n",index+1);
            else
                printf("-1\n");            
        }
    }
    return 0;
}