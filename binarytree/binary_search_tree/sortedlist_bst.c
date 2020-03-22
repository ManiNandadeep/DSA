#include<stdio.h>
#include<stdlib.h>
struct LNode
{
    int data;
    struct LNode*next;
};
struct TNode
{
    int data;
    struct TNode*lc;
    struct TNode*rc;
};
// UTILITY FUNCTIONS

//creates newnode
struct TNode* newNode(int data) 
{ 
    struct TNode* node = (struct TNode*) 
                         malloc(sizeof(struct TNode)); 
    node->data = data; 
    node->lc = NULL; 
    node->rc = NULL; 
  
    return node; 
} 
//prints preorder traversal
void preOrder(struct TNode* node) 
{ 
    if (node == NULL) 
        return; 
    printf("%d ", node->data); 
    preOrder(node->lc); 
    preOrder(node->rc); 
} 
//prints the nodes of a linked list
void printList(struct LNode *node) 
{ 
    while(node!=NULL) 
    { 
        printf("%d ", node->data); 
        node = node->next; 
    } 
} 
//returns number of nodes of a linked list
int countLNodes(struct LNode *head) 
{ 
    int count = 0; 
    struct LNode *temp = head; 
    while(temp) 
    { 
        temp = temp->next; 
        count++; 
    } 
    return count; 
} 
//function to insert a node at the beg of the linked list
void push(struct LNode**head_ref,int new_data)
{
    struct LNode*new_node=(struct LNode*)malloc(sizeof(struct LNode));
    new_node->data=new_data;
    new_node->next=*head_ref;
    *head_ref=new_node;
}
//code startes here--

struct TNode*sortedListToBSTUtil(struct LNode**head_ref,int n)
{
    if(n<=0)
        return NULL;
    struct TNode*left=sortedListToBSTUtil(head_ref,n/2);
    
    struct TNode*root=newNode((*head_ref)->data);
    root->lc=left;

    *head_ref=(*head_ref)->next;
    root->rc=sortedListToBSTUtil(head_ref,n-n/2-1);
    return root;
}

struct TNode* sortedListToBST(struct LNode*head)
{
    int n=countLNodes(head);
    return sortedListToBSTUtil(&head,n);
}
//code ends--
int main() 
{ 
    /* Start with the empty list */
    struct LNode* head = NULL; 
  
    /* Let us create a sorted linked list to test the functions 
     Created linked list will be 1->2->3->4->5->6->7 */
    push(&head, 7); 
    push(&head, 6); 
    push(&head, 5); 
    push(&head, 4); 
    push(&head, 3); 
    push(&head, 2); 
    push(&head, 1); 
  
    printf("\n Given Linked List "); 
    printList(head); 
  
    /* Convert List to BST */
    struct TNode *root = sortedListToBST(head); 
    printf("\n PreOrder Traversal of constructed BST "); 
    preOrder(root); 
  
    return 0; 
} 