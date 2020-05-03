class Solution {
public:
    long res=0,total=0,sub;
    int maxProduct(TreeNode* root) {
        total=s(root),s(root);
        return res%(int)(1e9+7);
    }
    int s(TreeNode*root)
    {
        if(!root) return 0;
        sub=root->val+s(root->left)+s(root->right);
        res=max(res,sub*(total-sub));
        return sub;
    }
  
};