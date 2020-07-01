#include<bits/stdc++.h>
using namespace std;
const int inf=1e5+5;
int p[inf],size[inf];
int Find(int i)
{
    if(p[i]==i) return i;
    else return p[i]=Find(p[i]);    //path compression
}

void Union(int i,int j)             //union by rank
{
    int ri=Find(i);
    int rj=Find(j);
    if(ri!=rj)
    {
        if(size[ri]>size[rj])
        {
            p[rj]=ri;
            size[ri]+=size[rj];
        }
        else
        {
            p[ri]=rj;
            size[rj]+=size[ri];
        }
    }
}


string SmallestStringSwaps(string s,vector<vector<int>>&pairs)
{
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        p[i]=i;
        size[i]=1;
    }
    for(auto v:pairs)           //union the indices of a pairs that can be swappable;
    {
        Union(v[0],v[1]);
    }
    unordered_map<int,vector<int>>Map;  //hash map from root to the indices that are swappable
    for(int i=0;i<n;i++)
    {
        Map[Find(i)].push_back(i);
    }
    for(auto m:Map)
    {
        string subseq="";              
        for(auto v:m.second)
        {
            subseq+=s[v];           
        }   
        sort(subseq.begin(),subseq.end());      //making "subseq" lexicographically smallest;
        int j=0;
        for(auto i:m.second)
        {
            s[i]=subseq[j++];               
        }
    }
    return s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);                   //fast io
    cout.tie(nullptr);
    cout<<"Input format\nfirst line--string\nsecond line--the number of rows in pairs 2d array(say 'm')\nnext m lines--mth pair"<<endl;
    string s;
    cin>>s;
    int rows;
    cin>>rows;
    vector<vector<int>>pairs(rows);
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<=1;j++)
        {
            int index; cin>>index;
            pairs[i].push_back(index);
        }
    }
    cout<<SmallestStringSwaps(s,pairs)<<endl;
}