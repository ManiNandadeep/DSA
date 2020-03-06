#include<stdio.h>
#include<stdlib.h>
#define MAX 100000
#define swap(a,b) {int (temp); temp = a; a = b; b = temp;}

void TopDownHeapify(int heap[], int length, int parent)
{
    int right_child = 2*parent + 2;
    int left_child = 2*parent + 1;
    while(right_child < length)
    {
        int max_child;
        if(heap[left_child] < heap[right_child])
            max_child = right_child;
        else
            max_child = left_child;

        if(heap[parent] > heap[max_child])
        {
            swap(heap[parent],heap[max_child]);
            parent = max_child;
            right_child = 2*parent + 2;
            left_child = 2*parent + 1;
        } 
        else
            break;
    }

    if(left_child<length && heap[parent]>heap[left_child])
    {
        swap(heap[parent],heap[left_child]);
    }
}

void BuildHeap(int heap[], int length)
{
    for(int i =length/2; i>=0; i--)
    {
        TopDownHeapify(heap, length, i);
    }
}

void HeapSort(int heap[], int length)
{
    BuildHeap(heap, length);
    for(int i =length-1; i>=0; i--)
    {
        swap(heap[0],heap[i]);
        TopDownHeapify(heap,i,0);
    }
    for(int i =0; i<length/2; i++)
    {
        swap(heap[i],heap[length-i-1]);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int* heap = malloc(n*sizeof(int));
    
    for(int i =0; i<n; i++)
    {
        scanf("%d",&heap[i]);
    }

    HeapSort(heap,n);

    for(int i =0; i<n; i++)
    {
        printf("%d ",heap[i]);
    }
    printf("\n");

    return 0;
}