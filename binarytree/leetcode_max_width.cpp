class Solution{
    public:
        int widthofBinaryTree(TreeNode*root){
            queue<pair<TreeNode*,int>>q;
            q.push(make_pair(root,1));
            int ans=0;
            while(!q.empty())
            {
                int s=q.size();
                if(s==1)  q.front().second=1;
                ans=max(ans,q.back().second-q.front().second+1);
                for(int i=0;i<s;i++)
                {
                    auto cur=q.front();
                    q.pop();
                    if(cur.first->lc) q.push(make_pair(cur.first->lc,2*cur.second));
                    if(cur.first->rc) q.push(make_pair(cur.first->rc,2*cur.second+1));
                }
            }
            return ans;
        }
};