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

    int left = ReturnMinQuery(A,ST,n,i,j,start,mid,2*root+1);
    int right = ReturnMinQuery(A,ST,n,i,j,mid+1,end,2*root+2);

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
void LastMin(int A[],int ST[],int i,int n)
{
    int p=0;
    while(p<n-1)
    {
        if(A[ST[2*p+2]]<=A[i]) p=2*p+2;
        else p=2*p+1;
    }
    printf("%d",A[ST[p]]);
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

    int index = ReturnMinQuery(A,ST,n,1,5,0,n-1,0); //Update range according to given query
    printf("Minimum value in given range (1,5) is %d\n",A[index]);
    LastMin(A,ST,0,n);
    return 0;
}
