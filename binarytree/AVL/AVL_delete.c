#include<stdio.h> 
#include<stdlib.h> 
  
struct Node 
{ 
    int key; 
    struct Node *lc; 
    struct Node *rc; 
    int height; 
}; 
  
int max(int a, int b); 
  
int height(struct Node *N) 
{ 
    if (N == NULL) 
        return 0; 
    return N->height; 
} 
  
int max(int a, int b) 
{ 
    return (a > b)? a : b; 
} 
  
struct Node* newNode(int key) 
{ 
    struct Node* node = (struct Node*) 
                        malloc(sizeof(struct Node)); 
    node->key   = key; 
    node->lc   = NULL; 
    node->rc  = NULL; 
    node->height = 1;  
    return(node); 
} 
  
struct Node *rightRotate(struct Node *y) 
{ 
    struct Node *x = y->lc; 
    struct Node *T2 = x->rc; 
  
    x->rc = y; 
    y->lc = T2; 
  
    y->height = max(height(y->lc), height(y->rc))+1; 
    x->height = max(height(x->lc), height(x->rc))+1; 
  
    return x; 
} 
  
struct Node *leftRotate(struct Node *x) 
{ 
    struct Node *y = x->rc; 
    struct Node *T2 = y->lc; 
  
    y->lc = x; 
    x->rc = T2; 
  
    x->height = max(height(x->lc), height(x->rc))+1; 
    y->height = max(height(y->lc), height(y->rc))+1; 
  
    return y; 
} 
  
int getBalance(struct Node *N) 
{ 
    if (N == NULL) 
        return 0; 
    return height(N->lc) - height(N->rc); 
} 
  
struct Node* insert(struct Node* node, int key) 
{ 
    /* 1.  Perform the normal BST insertion */
    if (node == NULL) 
        return(newNode(key)); 
  
    if (key < node->key) 
        node->lc  = insert(node->lc, key); 
    else if (key > node->key) 
        node->rc = insert(node->rc, key); 
    else // Equal keys are not allowed in BST 
        return node; 
  
    node->height = 1 + max(height(node->lc), 
                           height(node->rc)); 
  
    int balance = getBalance(node); 
  
    // If this node becomes unbalanced, then 
    // there are 4 cases 
  
    // Left Left Case 
    if (balance > 1 && key < node->lc->key) 
        return rightRotate(node); 
  
    // rc rc Case 
    if (balance < -1 && key > node->rc->key) 
        return leftRotate(node); 
  
    // Left rc Case 
    if (balance > 1 && key > node->lc->key) 
    { 
        node->lc =  leftRotate(node->lc); 
        return rightRotate(node); 
    } 
  
    // rc Left Case 
    if (balance < -1 && key < node->rc->key) 
    { 
        node->rc = rightRotate(node->rc); 
        return leftRotate(node); 
    } 
  
    return node; 
} 

void preOrder(struct Node *root) 
{ 
    if(root != NULL) 
    { 
        printf("%d ", root->key); 
        preOrder(root->lc); 
        preOrder(root->rc); 
    } 
} 
struct Node*minValueNode(struct Node*node)
{
    struct Node*current=node;
    while(current && current->lc!=NULL)
        current =current->lc;
    return current;
}
struct Node*deleteNode(struct Node*root,int key)
{
    //step1: normal bst delete
    if(root==NULL)
        return root;
    if(key < root->key)
        root->lc=deleteNode(root->lc,key);
    else if(key > root->key)
        root->rc=deleteNode(root->rc,key);
    else
    {
        if((root->lc==NULL) || (root->rc==NULL))
        {
            struct Node*tmp=root->lc ? root->lc:root->rc;
            if(tmp==NULL)
            {
                tmp=root;
                root=NULL;
            }
            else
            {
                *root=*tmp;
            }
            free(tmp);
        }   
        else
        {
            struct Node*tmp=minValueNode(root->rc);
            root->key=tmp->key;
            root->rc=deleteNode(root->rc,tmp->key);
        }
    }
    if(root == NULL)
        return root;
    //step2: update height of the current node
    root->height = 1+max(height(root->lc),height(root->rc));
    // get the balance factor of this node 
    // to check whether this node became unbalanced
    
    int balance=getBalance(root);
    //left left case
    if(balance>1 && getBalance(root->lc)>=0)
        return rightRotate(root);
    //right right case
    if(balance<-1 && getBalance(root->rc)<=0)
        return leftRotate(root);
    //left right case
    if(balance>1 && getBalance(root->lc)<0)
    {
        root->lc=leftRotate(root->lc);
        return rightRotate(root);
    }
    //right left case
    if(balance<-1 && getBalance(root->rc)>0)
    {
        root->rc=rightRotate(root->rc);
        return leftRotate(root);
    }
    return root;
}
int main() 
{ 
  struct Node *root = NULL; 
  
  /* Constructing tree given in the above figure */
    root = insert(root, 9); 
    root = insert(root, 5); 
    root = insert(root, 10); 
    root = insert(root, 0); 
    root = insert(root, 6); 
    root = insert(root, 11); 
    root = insert(root, -1); 
    root = insert(root, 1); 
    root = insert(root, 2); 
  
    printf("Preorder traversal of the constructed AVL "
           "tree is \n"); 
    preOrder(root); 
  
    root = deleteNode(root, 10); 
  
    printf("\nPreorder traversal after deletion of 10 \n"); 
    preOrder(root); 
  
    return 0; 
}