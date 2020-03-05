
#include<stdio.h>
#include<stdlib.h>
#define swap(a, b) {char (temp); temp = a; a = b; b = temp;}

void BottomUpHeapify(int i,int* Heap)
{
    int p = (i-1)/2;
    while(p>=0 && Heap[p] > Heap[i])
    {
        int temp = Heap[i];
        Heap[i] = Heap[p];
        Heap[p] = temp;
        i = p;
        p = (i-1)/2;
    }
}

void TopDownHeapify(int i,int n, int*Heap)
{
    int l =0;
    while(2*i+2 < n)
    {
        if( Heap[2*i+1] < Heap[2*i+2])
            l = 2*i+1;
        else
            l = 2*i+2;
        if(Heap[i] > Heap[l])
        {
            int temp = Heap[i];
            Heap[i] = Heap[l];
            Heap[l] = temp;
            i = l;
        }
        else
            break;
    }
    if(2*i+1<n && Heap[i] > Heap[2*i+1])
    {
        int temp = Heap[i];
        Heap[i] = Heap[2*i+1];
        Heap[2*i+1] = temp;
    }
}

void BuildHeap(int* Heap,int n)
{
    for(int i = 1;i<n;i++)
        BottomUpHeapify(i,Heap);
}

void BuildBetterHeap(int* Heap, int n)
{
    for(int i =n/2;i>=0;i--)
        TopDownHeapify(i,n,Heap);
}

void Add(int data,int*Heap,int *n)
{
    Heap[(*n)++] = data;
    BottomUpHeapify(*n-1,Heap);
}

void DeleteMin(int*Heap,int *n)
{
    Heap[0] = Heap[--(*n)];
    TopDownHeapify(0,*n,Heap);
}

void Update(int i, int data,int* Heap,int*n)
{
    if(Heap[i] < data)
    {
        Heap[i] = data;
        TopDownHeapify(i,*n,Heap);
    }
    else if( Heap[i] > data)
    {
        Heap[i] = data;
        BottomUpHeapify(i,Heap);
    }
}
void Delete(int i,int* Heap,int*n)
{
    Update(i,Heap[0] -1,Heap,n);
    DeleteMin(Heap,n);
}

void HeapSort(int* arr,int* n)
{
    BuildBetterHeap(arr,*n);
    (*n)--;
    swap(arr[0], arr[*n]);
    TopDownHeapify(0,*n,arr);        
    (*n)--;    
    while(*n>0)
    {
        swap(arr[0],arr[*n]);
        TopDownHeapify(0,*n,arr);         
        (*n)--;
    }

}
int main()
{
    int n;
    scanf("%d",&n);
    int a = n;
    int* count_ref = &n;
    int *arr= malloc(1000*sizeof(int));
    for(int i =0;i<n;i++)
        scanf("%d",&arr[i]);    
    // BuildHeap(arr,n);
    BuildBetterHeap(arr,*count_ref);
    // DeleteMin(arr,count_ref);
    // Add(2,arr,count_ref);
    // Update(4,1,arr,count_ref);
    // Delete(2,arr,count_ref);
    HeapSort(arr,count_ref  );
    for(int i=0;i<a;i++)
        printf("%d ",arr[i]);
    
    return 0;

}

