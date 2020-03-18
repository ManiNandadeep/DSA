#include<stdio.h>
#include<stdlib.h>
struct Node{
    int key;
    struct Node*lc,*rc;
};
struct Node*newnode(int item)
{
    struct Node*tmp=(struct Node*)malloc(sizeof(struct Node));
    tmp->key=item;
    tmp->lc= tmp->rc=NULL;
    return tmp;
}
void inorder(struct Node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->lc); 
        printf("%d \n", root->key); 
        inorder(root->rc); 
    } 
} 
struct Node*search(struct Node*root,int key)
{
    if(root == NULL || root->key == key)
    {
        return root;
    }
    if(root->key < key)
        return search(root->rc,key);
    return search(root->lc,key);
}
struct Node*insert(struct Node*node,int key)
{
    if(node==NULL)  return newnode(key);
    if(key < node->key)
        node->lc=insert(node->lc,key);
    else if(key > node->key)
        node->rc=insert(node->rc,key);
    return node;
}
struct Node*minValueNode(struct Node*node)
{
    struct Node*current=node;
    while(current && current->lc!=NULL)
        current =current->lc;
    return current;
}
struct Node* deleteNode(struct Node*root,int key)
{
    if(root == NULL) return root;
    if (key < root->key)
        root->lc=deleteNode(root->lc,key);
    else if (key > root->key)
        root->rc=deleteNode(root->rc,key);
    else{
        if(root->lc == NULL)
        {
            struct Node*tmp=root->rc;
            free(root);
            return tmp;
        }
        else if (root->rc ==NULL)
        {
            struct Node*tmp=root->lc;
            free(root);
            return tmp;
        }
        struct Node*tmp=minValueNode(root->rc);
        root->key=tmp->key;
        root->rc=deleteNode(root->rc,tmp->key);
    }
    return root;
}
int main(void)
{
    struct Node *root = NULL; 
    root = insert(root, 50); 
    root = insert(root, 30); 
    root = insert(root, 20); 
    root = insert(root, 40); 
    root = insert(root, 70); 
    root = insert(root, 60); 
    root = insert(root, 80);

    printf("Inorder traversal of the given tree \n"); 
    inorder(root); 

    printf("\nDelete 20\n"); 
    root = deleteNode(root, 20); 
    printf("Inorder traversal of the modified tree \n"); 
    inorder(root);

    printf("\nDelete 30\n"); 
    root = deleteNode(root, 30); 
    printf("Inorder traversal of the modified tree \n"); 
    inorder(root);

    printf("\nDelete 50\n"); 
    root = deleteNode(root, 50); 
    printf("Inorder traversal of the modified tree \n"); 
    inorder(root);

    return 0;
}