#include <bits/stdc++.h>
using namespace std;
int vis[100005],arr[100005];
queue<pair<int,int> >q;
//best way -- donot use level array,donot use 1 based indexing,never forget to do arr[i]%n while scaning 
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,i,st,de;
        cin>>n>>st>>de;
        st--;
        de--;
        memset(vis,0,sizeof(vis));
        while(!q.empty())
            q.pop();
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
            arr[i]%=n;
        }
        vis[st]=1;
        q.push(make_pair(st,0));
        int ans=-1;
        while(!q.empty())
        {
            pair<int,int> temp=q.front();
            q.pop();
            if(temp.first==de)
            {
                ans=temp.second;
                break;
            }
            int nextb=(temp.first-arr[temp.first]+n)%n;
            int nextf=(temp.first+arr[temp.first])%n;
            if(!vis[nextb])
            {
                vis[nextb]=1;
                q.push(make_pair(nextb,temp.second+1));
            }
            if(!vis[nextf])
            {
                vis[nextf]=1;
                q.push(make_pair(nextf,temp.second+1));
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}