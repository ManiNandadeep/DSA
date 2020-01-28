#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct node{
    int data;
    struct node* next;
};

void Insert(struct node** head, int data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = (*head);
    (*head) = new_node;
}

void Delete(struct node** head, int data)
{
    if((*head) != NULL)
    {
        struct node* prev_node = (*head);
        struct node* temp;
        if(prev_node->data == data)
        {
            (*head) = (*head)->next;
            free(prev_node);
            return;
        }

        while(prev_node!= NULL && prev_node->data != data)
        {
            temp = prev_node;
            prev_node = prev_node->next;
        }

        if(prev_node==NULL)
            return;

        temp->next = prev_node->next;
        free(prev_node);
    }
}

int ABS(int data)
{
    if(data<0)
        return -data;
    else
        return data;
}

int FindMax(struct node* head)
{
    int max = head->data;
    while(head!= NULL)
    {
        if(head->data > max)
            max = head->data;
        head = head->next;
    }
    return max;
}

bool Search(struct node* head, int data)
{
    while (head != NULL)
    {
        if(head->data == data)
            return true;
        head = head->next;
    }
    return false;
}

void printList(struct node* head)
{
    while (head != NULL)
    {
        printf("%d  ",head->data);
        head = head->next;
    }
    printf("NULL\n");
}

bool Possible(struct node** head,int points[],int n, int max, int left, int right)
{
    int array[1000];
    int index = 0;
    int flag = true;
    for(int i = 0; i<left; i++)
    {
        array[index++] = ABS(points[i]-max);
    }
    for(int i = right+1; i<n; i++)
    {
        array[index++] = ABS(points[i]-max);
    }
    int i = 0;

    for(i; i<index; i++)
    {
        if(Search((*head),array[i]))
        {
            Delete(head,array[i]);
        }
        else
        {
            flag = false;
            break;
        }
    }

    for(int j= 0; j<i; j++)
    {
        Insert(head,array[j]);
    }

    return flag;
}


bool Try(int points[], struct node** head, int n, int left, int right)
{
    bool found = false;
    if((*head) == NULL)
        return true;
    
    int max = FindMax((*head));

    if(Possible(head,points,n,max,left,right))
    {
        points[right] = max;
        for(int i = 0; i<left; i++)
        {
            Delete(head,ABS(points[i]-points[right]));
        }
        for(int i = right +1; i<n; i++)
        {
            Delete(head,ABS(points[i]-points[right]));
        }

        found = Try(points,head,n,left,right-1);

        if(found == false)
        {
            for(int i = 0; i<left; i++)
            {
                Insert(head,ABS(points[i]-points[right]));
            }
            for(int i = right +1; i<n; i++)
            {
                Insert(head,ABS(points[i]-points[right]));
            }
        }
    }

    if(Possible(head,points,n,points[n-1]-max,left,right) && found == false)
    {
        points[left] = points[n-1] - max;
        for(int i=0; i<left; i++)
        {
            Delete(head, ABS(points[i]-points[left]));
        }
        for(int i=right +1; i<n; i++)
        {
            Delete(head, ABS(points[i]-points[left]));
        }

        found = Try(points,head,n,left+1,right);

        if(found == false)
        {
            for(int i = 0; i<left; i++)
            {
                Insert(head,ABS(points[i]-points[left]));
            }
            for(int i = right +1; i<n; i++)
            {
                Insert(head,ABS(points[i]-points[left]));
            }
        }
    }
    return found;
}

bool reconstruct(int points[],struct node** head,int n)
{
    points[0] = 0;
    points[n-1] = FindMax((*head));
    Delete(head,FindMax((*head)));
    points[n-2] = FindMax((*head));
    Delete(head,FindMax((*head)));
    if(Search((*head),points[n-1]-points[n-2]))
    {
        Delete(head, points[n-1]-points[n-2]);
        return Try(points,head,n,1,n-3);
    }
    else
        return false;
}

int main()
{
    struct node* head = NULL;
    int D[] = {1,1,2,2,2,3,3,3,4,5,5,5,6,7,8,10};
    for(int i= 0; i<15; i++)
    {
        Insert(&head,D[i]);
    }
    int points[1000];

    if(reconstruct(points,&head,6))
    {
        for(int i =0; i<6; i++)
        {
            printf("%d  ",points[i]);
        }
        printf("\n");
    }
    else
    {
        printf("cannot find a solution\n");
    }

    return 0;
}