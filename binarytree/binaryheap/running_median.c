#include<stdio.h>
#include<stdlib.h>
struct minHeap{
    int capacity;
    int size;
    int *elements;
};
struct maxHeap{
    int capacity;
    int size;
    int *elements;
};
typedef struct{
    struct minHeap*minH;
    struct maxHeap*maxH;
} MedianFinder;

MedianFinder*medianFinderCreate()
{
    MedianFinder*MF_Heap=(MedianFinder*)malloc(sizeof(MedianFinder));
    MF_Heap->maxH=(struct maxHeap*)malloc(sizeof(struct maxHeap));
    MF_Heap->maxH->capacity=10000;
    MF_Heap->maxH->size=0;
    MF_Heap->maxH->elements=(int*)malloc(sizeof(int)*(10001));
    MF_Heap->maxH->elements[0]=2147483647;

    MF_Heap->minH=(struct minHeap*)malloc(sizeof(struct minHeap));
    MF_Heap->minH->capacity=10000;
    MF_Heap->minH->size=0;
    MF_Heap->minH->elements=(int*)malloc(sizeof(int)*(10001));
    MF_Heap->minH->elements[0]=-2147483648;

    return MF_heap;
}
int getmax(struct maxHeap*H)
{
    return H->elements[1];
}
int getmin(struct minHeap*H)
{
    return H->elements[1];
}
void maxInsert(struct maxHeap*H,int x)
{
    int i;
    for(i=++H->size;H->elements[i/2]<x;i=i/2)
    {
        H->elements[i]=H->elements[i/2];
    }
    H->elements[i]=x;
}
void minInsert(struct minHeap*H,int x)
{
    int i;
    for(i=++H->size;H->elements[i/2]>x;i=i/2)
    {
        H->elements[i]=H->elements[i/2];
    }
    H->elements[i]=x;
}
void minDelete(struct minHeap*H)
{
    int i;
    int child;
    int min=H->elements[1];
    int last=H->elements[H->size--];
    for(i=1;2*i<=H->size;i=i/2)
    {
        child=2*i;
        if(child!=H->size && H->elements[child] > H->elements[child+1])
        {
            child++;
        }
        if(H->elements[child]<last)
        {
            H->elements[i]=H->elements[child];
        }
        else
        {
            break;
        }
    }   
    H->elements[i]=last;
}
void maxDelete(struct maxHeap*H)
{
    int i;
    int child;
    int max=H->elements[1];
    int last=H->elements[H->size--];
    for(i=1;2*i<H->size;i=child)
    {
        child=2*i;
        if(child!=H->size && H->elements[child] < H->elements[child+1])
        {
            child++;
        }
        if(H->elements[child] > last)
        {
            H->elements[i]=H->elements[child];
        }
        else
        {
            break;
        }
    }    
    H->elements[i]=last;
}
void medianFinderAddNum(MedianFinder*obj,int num)
{
    if(obj->maxH->size ==0)
    {
        maxInsert(obj->maxH,num);
        return ;
    }
    if(obj->minH->size ==obj->maxH->size)
    {
        if(num < getmax(obj->maxH))
        {
            maxInsert(obj->maxH,num);
        }
        else
        {
            minInsert(obj->minH,num);
        }
    }
    else if (obj->maxH->size > obj->minH->size)
    {
        int tmp;
        if(num >getmax(obj->maxH))
        {
            minInsert(obj->minH,num);
        }
        else
        {
            tmp=getmax(obj->maxH);
            maxDelete(obj->maxH);
            minInsert(obj->minH,tmp);
            maxInsert(obj->maxH,num);
        }
    }
    else if (obj->maxH->size < obj->minH->size)
    {
        int tmp;
        if(num<getmin(obj->minH))
        {
            maxInsert(obj->maxH,num);
        }
        else
        {
            tmp=getmin(obj->minH);
            minDelete(obj->minH);
            maxInsert(obj->maxH,tmp);
            minInsert(obj->minH,num);
        }
        
    }
}
double medianFinderFindMedian(MedianFinder*obj)
{
    double median;
    if(obj->maxH->size ==obj->minH->size)
    {
        median=(getmin(obj->minH)+getmax(obj->maxH))/2.0;
    }
    else if(obj->maxH->size > obj->minH->size)
    {
        median=getmax(obj->maxH);
    }
    else if(obj->maxH->size < obj->minH->size)
    {
        median=getmin(obj->min);
    }
    return median;
}
void medianFinderFree(MedianFinder*obj)
{
    free(obj->maxH->elements);
    free(obj->minH->elements);
    free(obj->maxH);
    free(obj->maxH);
    free(obj);
}