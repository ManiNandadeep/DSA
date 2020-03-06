 
#include<stdio.h>
#include<stdlib.h>
#define MAX 10000
#define swap(a,b) {int (temp); temp = a; a = b; b = temp;}

void BottomUpHeapify(int heap[], int child)
{
    int parent = (child-1)/2;

    while(parent >= 0 && heap[parent]>heap[child])
    {
        swap(heap[child],heap[parent]);
        child = parent;
        parent = (child-1)/2;
    }
}

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

void DeleteMin(int heap[], int length)
{
    heap[0] = heap[--length];
    TopDownHeapify(heap, length, 0);
}

void Update(int heap[], int length, int index, int data)
{
    if(heap[index] < data)
    {
        heap[index] = data;
        TopDownHeapify(heap, length, index);
    }
    else if(heap[index] > data)
    {
        heap[index] = data;
        BottomUpHeapify(heap, index);
    }
}

void Delete(int heap[], int length, int index)
{
    Update(heap, length, index, heap[0]-1);
    DeleteMin(heap, length);
}

void BuildHeap(int heap[], int length)
{
    for(int i =length/2; i>=0; i--)
    {
        TopDownHeapify(heap, length, i);
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

    BuildHeap(heap, n);
    int length = n;

    for(int i =0; i<length; i++)
    {
        printf("%d ",heap[i]);
    }
    printf("\n");

    int index;
    scanf("%d",&index);
    Delete(heap, length, index);
    length--;

    for(int i =0; i<length; i++)
    {
        printf("%d ",heap[i]);
    }
    printf("\n");    

    return 0;
}