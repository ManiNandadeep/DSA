class Solution{
public:
    struct Node{
        int val;
        struct Node*child[2];
         Node(){
             val=0;
             child[0]=child[1]=NULL;
         }
    };
    struct Node*start=new Node();
    void insertTrie(int x){
        struct Node*ptr=start;
        for(int i=31;i>=0;i--)
        {
            bool curbit=(x&(1<<i));
            if(!ptr->child[curbit])
                ptr->child[curbit]=new Node();
            ptr=ptr->child[curbit];
        }
        ptr->val=x;
    }
    int checkTrie(int x)
    {
        struct Node*ptr=start;
        for(int i=31;i>=0;i--)
        {
            bool curbit=(x&(1<<i));
            if(ptr->child[1-curbit])
                ptr=ptr->child[1-curbit];
            else if(ptr->child[curbit])
                ptr=ptr->child[curbit];
        }
        return ptr->val;
    }
    int findMaximumXOR(vector<int>&nums)
    {
        int ans=0,n=nums.size();
        if(nums.size()<2) return 0;
        insertTrie(nums[0]);
        for(int i=1;i<n;i++)
        {
            ans=max(ans,nums[i]^checkTrie(nums[i]));
            insertTrie(nums[i]);
        }
        return ans;
    }
};