#include<bits/stdc++.h>
using namespace std;

void dfs(long i, vector<int> adj[], bool v[], long d[])
{
	v[i]=true;
	for(auto j:adj[i])
	{
		if(!v[j])
		{
			d[j]=d[i]+1;
			dfs(j,adj,v,d);
		}
	}
}
int main()
{ 
	long n, i, j, x, sum, m, mindep=-1;
	cin>>n>>x;
 
	vector<int> adj[n+1];
	bool v[n+1];
	long d[n+1], val[n+1], deg[n+1];
 
	for(i=0; i<=n; i++)
	{
		deg[i]=0;
		v[i]=false;
	}
 
	for(i=1; i<=n; i++)
	cin>>val[i];

 
	for(int k=0;k<n-1;k++)
	{
		cin>>i>>j;
		adj[i].push_back(j);
		adj[j].push_back(i);
		deg[i]++;
		deg[j]++;
	}
	d[1]=1;
 
	dfs(1, adj, v, d);
 
	for(i=2; i<=n; i++)
	{
		if(deg[i]<3)
		{
			if(mindep==-1)
			{
				mindep=d[i]+1;
			}else if(mindep>d[i]+1)
			{
				mindep=d[i]+1;
			}
		}
	}
	if(deg[1]==1)
		{
			mindep=2;
		}
	sum=x*mindep;
 
	for(i=1; i<=n; i++)
	{
		sum=sum+val[i]*d[i];
	}
	cout<<sum;
}