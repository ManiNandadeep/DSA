class Solution {
public:
    int res=0;
    int findTilt(TreeNode* root) {
        postOrder(root);
        return res;
    }
    int postOrder(TreeNode*root)
    {
        if(!root) return 0;
        int l=postOrder(root->left);
        int r=postOrder(root->right);
        res+=abs(l-r);
        return l+r+root->val;
    }
    
};