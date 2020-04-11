class Solution{
    int ans;
    public:
        int depth(TreeNode*root)
        {
            if(root==NULL)
                return 0;
            int l=depth(root->left);
            int r=depth(root->right);
            ans=max(ans,l+r+1);
            return max(l,r)+1;
        }
        int diameterOfBinaryTree(TreeNode*root)
        {
            ans=1;
            depth(root);
            return ans-1;
        }

};