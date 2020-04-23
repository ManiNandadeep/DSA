class Solution {
public:
    int i=0;
    TreeNode* bstFromPreorder(vector<int>& preorder,int bound=INT_MAX) {
           if(i==preorder.size() || preorder[i]>bound) return NULL;
            TreeNode*Node=new TreeNode(preorder[i++]);
            Node->left=bstFromPreorder(preorder,Node->val);
            Node->right=bstFromPreorder(preorder,bound);
            return Node;
    }
};