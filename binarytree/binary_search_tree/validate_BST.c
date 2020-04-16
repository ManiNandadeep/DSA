class Solution{
  public:
    bool isValidBST(TreeNode*root)
    {
      TreeNode*prev=NULL;
      return validate(root,prev);
    }
    bool validate(TreeNode*root,TreeNode* &prev)
    {
      if(root==NULL) return true;
      if(!validate(root->left,prev)) return false;
      if(prev!=NULL && prev->val >=root->val) return false;
      prev=root;
      return validate(root->right,prev);
    } 
};
