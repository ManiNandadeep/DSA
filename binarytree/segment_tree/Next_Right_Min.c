#include<stdio.h>
#include<stdlib.h>
#define MAX 100000
#define INT_MAX 2147483647	

void Build(int A[], int ST[], int n)
{
    for(int i = 0; i<n; i++)
    {
        ST[n-1+i] = i;
    }
    for(int i = n-2; i > -1; i--)
    {
        if(A[ST[2*i+1]] > A[ST[2*i+2]])
        {
            ST[i] = ST[2*i+2];
        }
        else
        {
            ST[i] = ST[2*i+1];
        }
    }
}

void Update(int A[], int ST[], int n, int index, int value)
{
    A[index] = value;
    int parent = ((n-1+index)-1)/2;

    while( parent > 0)
    {
        if(A[ST[2*parent+1]] > A[ST[2*parent+2]])
        {
            ST[parent] = ST[2*parent+2];
        }
        else{
            ST[parent] = ST[2*parent+1];
        }
        parent = (parent-1)/2;
    }

    ST[0] = A[ST[1]] > A[ST[2]] ? ST[2] : ST[1];
}

int ReturnMinQuery(int A[], int ST[], int n, int i, int j, int start, int end, int root)
{    
    if (start > j || end < i)
    {
        return n;
    }
    else if (start >= i && end <= j)
    {
        return ST[root];
    }

    int mid = (start+end)/2;

    int right = ReturnMinQuery(A,ST,n,i,j,mid+1,end,2*root+2);
    int left = ReturnMinQuery(A,ST,n,i,j,start,mid,2*root+1);

    if(A[left] < A[right])
        return left;
    else
        return right;
}

void PrintST(int ST[], int n)
{
    for(int i= 0; i<2*n-1 ; i++)
    {
        printf("%d ",ST[i]);
    }
    printf("\n");
}
int Next_Right_Min(int A[],int ST[],int n,int i)
{
    int p=0,s=0,e=n-1,j=n;
    while(p<n-1)
    {
        int m=(s+e)/2;
        // printf("%d",m);
        if(i<=m)
        {
            if(A[ST[2*p+2]]<A[i]) j=2*p+2;
            p=2*p+1;
            e=m;
        }
        else
        {
            p=2*p+2;
            s=m+1;
        }

        //printf("value of p,s,e,m,j is %d,%d,%d,%d,%d\n",p,s,e,m,j);
    }
    while(j<n-1)
    {
        if(A[ST[2*j+1]]<A[i])
            j=2*j+1;
        else j=2*j+2;
    }
    return j;
}
int main()
{
    int n; int A[MAX];
    int ST[MAX];

    scanf("%d",&n);

    for(int i= 0; i<n ; i++)
    {
        scanf("%d",&A[i]);
    }

    A[n] = INT_MAX;

    Build(A,ST,n);
    printf("Built Segment Tree - ");
    PrintST(ST,n);

   Update(A,ST,n,1,1); //Update element according to given query 
    Update(A,ST,n,6,14);
    printf("Updated Segment Tree - ");
    PrintST(ST,n);

    int index = ReturnMinQuery(A,ST,n,1,7,0,n-1,0); //Update range according to given query
    printf("Minimum value in given range (1,5) is %d\n",index);
    
    int index1=Next_Right_Min(A,ST,n,1);
    if(index1==n)
        printf("No such number exists");
    else
        printf("The next right min of given index is %d\n",A[index1]);
    return 0;
}
