#include<stdio.h>
#include<stdlib.h>
#define P 997
#define SIZE 10000
#define swap(a,b) {struct heap(temp);temp=a;a=b;b=temp;}
struct hash{
    int data,count,iheap;
    struct hash*next;
    struct hash*prev;
};
struct heap{
    int count;
    struct hash*ptr;
};

int length=0;
int hashValue(int value)
{
    int tmp=value%P;
    if(tmp<=0)
        tmp+=P;
    return tmp;
}
void BottomUpHeapify(struct heap Heap[], int c)
{
    int p = (c-1)/2;

    while(p >= 0 && Heap[p].count<Heap[c].count)
    {
        swap(Heap[c],Heap[p]);
        Heap[c].ptr->iheap=c;
        Heap[p].ptr->iheap=p;
        c = p;
        p = (c-1)/2;
    }
}
void TopDownHeapify(struct heap Heap[], int p)
{
    int right_child = 2*p + 2;
    int left_child = 2*p + 1;
    while(right_child < length)
    {
        int max_child;
        if(Heap[left_child].count < Heap[right_child].count)
            max_child = right_child;
        else
            max_child = left_child;

        if(Heap[p].count < Heap[max_child].count)
        {
            swap(Heap[p],Heap[max_child]);
            Heap[p].ptr->iheap=p;
            Heap[max_child].ptr->iheap=max_child;
            p = max_child;
            right_child = 2*p + 2;
            left_child = 2*p + 1;
        } 
        else
            break;
    }

    if(left_child<length && Heap[p].count < Heap[left_child].count)
    {
        swap(Heap[p],Heap[left_child]);
        Heap[p].ptr->iheap=p;
        Heap[left_child].ptr->iheap=left_child;
    }
}
void HeapAdd(struct heap Heap[],struct hash**head)
{
    Heap[length++].count=1;
    Heap[length-1].ptr=*head;
    BottomUpHeapify(Heap, length-1);
}

void add_at_beg(struct hash**head,int value)
{
    struct hash*tmp=(struct hash*)malloc(sizeof(struct hash));
    tmp->data=value;
    tmp->count=1;
    tmp->iheap=length;
    tmp->next=*head;
    tmp->prev=NULL;
    if(*head) (*head)->prev=tmp;
    *head=tmp;
}
void deleteListNode(struct hash**head,struct hash*del_node)
{
    if(*head==NULL || del_node==NULL)
        return;
    if(*head==del_node)
        *head=del_node->next;
    if(del_node->next)
        del_node->next->prev=del_node->prev;
    if(del_node->prev)
        del_node->prev->next=del_node->next;
    free(del_node);
    return;
}

void Add(struct hash*hashtable[],struct heap Heap[],int value)
{
     struct hash*tmp=hashtable[hashValue(value)];
     int flag=0;
     while(hashtable[hashValue(value)]){
         if(hashtable[hashValue(value)]->data==value)
         {
             hashtable[hashValue(value)]->count++;
             int new_count=hashtable[hashValue(value)]->count;
             Heap[hashtable[hashValue(value)]->iheap].count=new_count;
             BottomUpHeapify(Heap,hashtable[hashValue(value)]->iheap);
             flag=1;
             break;
         }
         hashtable[hashValue(value)]=hashtable[hashValue(value)]->next;
     }    
    // hashtable[hashValue(value)]=tmp;
    if(flag==0){
     add_at_beg(&hashtable[hashValue(value)],value);
     HeapAdd(Heap,&hashtable[hashValue(value)]);  
    }
}

void DeleteMax(struct heap Heap[],struct hash*hashtable[])
{
    int max=Heap[0].count;
    // int number=Heap[0].ptr->data;
    while(Heap[0].count==max){
    
        deleteListNode(&hashtable[hashValue(Heap[0].ptr->data)],Heap[0].ptr);
        if(length==1){
            length--;
            break;
        }
        Heap[0]=Heap[--length];
        Heap[0].ptr->iheap=0;
        TopDownHeapify(Heap,0);
    }
}
void print_hash(struct hash*hashtable[])
{
    for(int i=1;i<=P;i++)
    {
        struct hash*tmp=(struct hash*)malloc(sizeof(struct hash));
        tmp=hashtable[i];
        while(tmp)
        {
            printf("value-> %d , count-> %d\n",tmp->data,tmp->count);
            tmp=tmp->next;
        }
    }
}

int main()
{
    struct hash*hashtable[SIZE]={0};
    struct heap Heap[SIZE];
    Add(hashtable,Heap,1);
    Add(hashtable,Heap,1);
    Add(hashtable,Heap,1);
    Add(hashtable,Heap,1);
    Add(hashtable,Heap,2);
    DeleteMax(Heap,hashtable);
    print_hash(hashtable);
    Add(hashtable,Heap,2);
    Add(hashtable,Heap,2);
    Add(hashtable,Heap,2);
    Add(hashtable,Heap,2);
    Add(hashtable,Heap,3);
    Add(hashtable,Heap,3);
    Add(hashtable,Heap,3);
    DeleteMax(Heap,hashtable);
    print_hash(hashtable);
    return 0;    
}
