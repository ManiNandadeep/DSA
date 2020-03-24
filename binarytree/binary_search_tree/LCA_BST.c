/*this solution uses the bst property 
        that the nodes in the left subtree are smaller than 
            the value of the root and the nodes in the right subtree are larger than 
                the value of the root*/
//recursive solution starts --
struct Node*lca_recursive(struct Node*root,int n1,int n2)
{
    if(root==NULL)
        return NULL;
    if(root->data >n1 && root->data >n2)
        return lca_recursive(root->lc,n1,n2);
    else if(root->data <n1 && root->data <n2)
        return lca_recursive(root->rc,n1,n2);
    return root;
}
//recursive solution ends--
//iterative solution starts --
struct Node*lca(struct Node*root,int n1,int n2)
{
    while (root!=NULL)
    {
        if(root->data > n1 && root->data >n2)       
            root=root->lc;
        else if(root->data <n1 && root->data <n2)
            root=root->rc;
        else break;
    }
    return root;
}
//iterative solution ends--