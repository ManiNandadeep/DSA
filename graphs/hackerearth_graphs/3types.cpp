#include<bits/stdc++.h>
using namespace std;
vector<int>p(10005);
vector<int>S(10005,0);
int n,m;
int a,b,c;
int find(int i)
{
    if(p[i]==i) return i;
    else return p[i]=find(p[i]);
}
int Krushkal(vector<pair<int,int>>edges,int count)
{
    for(int i=0;i<edges.size();i++)
    {
        int a=find(edges[i].first);
        int b=find(edges[i].second);
        if(a!=b)
        {
            // p[a]=b;
            if(S[a]>S[b])
            {
                S[a]+=S[b];
                p[b]=a;
            }
            else{
                S[b]+=S[a];
                p[a]=b;
            }
            count++;
        }
    }
    return count;
}
int main()
{
    cin>>n>>m;
    vector<pair<int,int>>edge1,edge2,edge3;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        if(c==1)
        {
            edge1.push_back(make_pair(a,b));
        }
        else if(c==2)
        {
            edge2.push_back(make_pair(a,b));
        }
        else{
            edge3.push_back(make_pair(a,b));
        }
    }
    for(int i=0;i<n+1;i++) p[i]=i;
    int type3=0,type13=0,type23=0;
    type3=Krushkal(edge3,type3);
    type13=Krushkal(edge1,type3);
    for(int i=0;i<n+1;i++) p[i]=i;
    type3=0;
    type3=Krushkal(edge3,type3);
    type23=Krushkal(edge2,type3);
    if(type23<n-1||type13<n-1) cout<<-1<<endl;
    else{
        cout<<m-type23-type13+type3<<endl;
    }    
    return 0;
}