#include<bits/stdc++.h>
using namespace std;
#define inf 200005
int n,k;
int main()
{
//     vector<int>graph[inf];
// bool bt[inf]={false};
// int deg[inf]={0};
// bool V[inf]={false};
// queue<int>q;
    cin>>n>>k;
    vector<int>graph[n+1];
    bool bt[n+1]={false};
    int deg[n+1]={0};
    bool V[n+1]={false};
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        deg[u]++,deg[v]++;
    }
    for(int i=0;i<k;i++)
    {
        int b;
        cin>>b;
        bt[b]=true;
    }
    queue<int>q;
    for(int i=1;i<=n;i++) if(deg[i]==1&&!bt[i]) q.push(i),V[i]=true;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        n--;
        for(auto &v:graph[u])
        {
            deg[v]--;
            if(deg[v]==1&&!bt[v]&&!V[v]) q.push(v),V[v]=true;
        }
    }
    cout<<n;
}
