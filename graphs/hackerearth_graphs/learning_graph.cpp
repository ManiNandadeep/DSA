#include<bits/stdc++.h>
using namespace std;
vector<int>graph[1005];
int val[1005];
bool compare(int a,int b)
{
    if(val[a]==val[b]) return a>b;
    else return val[a]>val[b];
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>val[i];
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        sort(graph[i].begin(),graph[i].end(),compare);
        if(graph[i].size()<k) cout<<"-1\n";
        else cout<<graph[i][k-1]<<"\n";
    }
    return 0;
}