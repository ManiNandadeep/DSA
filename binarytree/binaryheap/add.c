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

void Add(int heap[], int length, int data)
{
    heap[length++] = data;
    BottomUpHeapify(heap, length-1);
}

int main()
{
    int n;
    scanf("%d",&n);
    int* heap = malloc(n*sizeof(int));
    
    int length = 0;
    for(int i =0; i<n; i++)
    {
        int data;
        scanf("%d",&data);
        Add(heap, length, data);
        length++;
    }

    for(int i =0; i<n; i++)
    {
        printf("%d ",heap[i]);
    }
    printf("\n");

    return 0;
}