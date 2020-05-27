#include<bits/stdc++.h>
using namespace std;
#define inf 100005
int n,q,dp[inf][26];
// char ch[inf];
vector<int>graph[inf];
void dfs(vector<bool>&V,char ch[],int u)
{
    V[u]=true;
    for(auto v:graph[u])
    {
        if(!V[v])
        {
            dfs(V,ch,v);
            for(int i=0;i<26;i++) dp[u][i]+=dp[v][i];
        }
    }
    dp[u][ch[u]-'a']++;
}
int main(void)
{
    cin>>n>>q;
    char ch[n];
    for(int i=1;i<=n;i++) cin>>ch[i];
    for(int i=1;i<=n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<bool>V(n,false);
    dfs(V,ch,1);
    while(q--)
    {
        int x;
        string s;
        cin>>x>>s;
        int arr[30]={0};
        int ans=0;
        for(int i=0;i<s.size();i++) arr[s[i]-'a']++;
        for(int i=0;i<26;i++)
        {
            ans+=max(0,arr[i]-dp[x][i]);
        }
        cout<<ans<<"\n";
    }
}