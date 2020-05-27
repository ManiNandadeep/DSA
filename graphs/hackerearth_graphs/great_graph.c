#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#define ll long long
ll int  n,m,k,u,v;
struct List{
  ll int i;
  struct List*next;
};
struct List*list[100000];
bool V[100000]={false};
struct List *
newedge (struct List *node, ll int i)
{
  struct List *temp = (struct List *) malloc (sizeof (struct List));
  temp->i = i;
  temp->next = node;
  return temp;
}
void dfs(ll int x,ll int r,ll int s)
{
  V[x]=true;
  if(s>v)
  {
    u=x;
    v=s;
  }
  struct List*temp=list[x];
  while(temp)
  {
    if(!V[temp->i])
    { 
      if(temp->i!=r) dfs(temp->i,x,s+1);
    }    
    temp=temp->next;
  }
}

int main()
{
  ll int ans=0;
  scanf("%lld %lld %lld",&n,&m,&k);
  while(m--)
  {
    ll int x,y;
    scanf("%lld %lld",&x,&y);
    list[x-1]=newedge(list[x-1],y-1);
    list[y-1]=newedge(list[y-1],x-1);
  }
  for(ll int i=0;i<n;i++)
  {
    if(!V[i])
    {
      u=0;
      v=-1;
      dfs(i,0,0);
      ll int z=u;
      u=0;
      v=-1;
      dfs(z,0,1);
      if(v>ans) ans=v;
    }
  }
  printf("%lld",(ans+k-1)/k);
  return 0;
}