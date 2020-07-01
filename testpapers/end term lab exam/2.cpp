#include<bits/stdc++.h>
using namespace std;
const int inf=2e3+5;
int p[inf],size[inf];

int find(int i)
{
    if(p[i]==i) return i;
    else return p[i]=find(p[i]);    //path compression
}
/* idea--
    A graph is not a rooted tree if
    1) a node has more than one parent
    2) there is a cycle in the graph
*/
vector<int>FindRedundantConn(vector<vector<int>>&edges)
{
    int n=edges.size();
    for(int i=1;i<=n;i++) p[i]=i,size[i]=1;
    vector<int>edge1,edge2,cycle;
    unordered_map<int,int>Map;
    for(auto& edge:edges)
    {
        if(Map.count(edge[1])>0)                //if encountered edge[1] already has a parent i.e edge[1] has more than 1 parent;
        {
            edge2=edge;                            
            edge1=vector<int>{Map[edge[1]],edge[1]};
        }
        else
        {
            Map[edge[1]]=edge[0];       //assign edge[0] as the parent of edge[1];
            int a=find(edge[0]);
            int b=find(edge[1]);
            if(a==b)                    //if edge[0] and edge[1] has the same roots there is a cycle
            {
                cycle=edge;
            }
            else                        //else merge them by using union by rank
            {
                if(size[a]>size[b])
                {
                    size[a]+=size[b];
                    p[b]=a;
                }
                else{
                    size[b]+=size[a];
                    p[a]=b;
                }
            }
            
        }
        
    }
    /*
        if there is cycle and edge1,edge2 are non-empty then return edge1;
        sample test case is [[1,2],[2,3],[3,1],[4,3]] where edge1 is [2,3] and edge2 is [4,3] and edge1 is returned to retore the rooted tree structure 
    */
    if(edge1.size()>0 and edge2.size()>0) return cycle.size()>0?edge1:edge2;  
    return cycle;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);                       //fastio
    cout.tie(nullptr);
    cout<<"Input format\nfirst line--number of rows in edges array(say 'm')\nnext m lines--mth edge"<<endl;
    int rows;
    cin>>rows;
    vector<vector<int>>edges(rows);
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<=1;j++)
        {
            int x;cin>>x;
            edges[i].push_back(x);
        }
    }
    vector<int>ans=FindRedundantConn(edges);
    cout<<"["<<ans[0]<<","<<ans[1]<<"]"<<endl ;
}