#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
struct List{
    int i;
    struct List*next;
};

struct List *
newedge (struct List *node, int i)
{
struct List *temp = (struct List *) malloc (sizeof (struct List));
temp->i = i;
temp->next = node;
return temp;
}
int max(int a,int b)
{
    if(a>b) return a;
    else return b;
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    struct List*G[n];
    struct List*G`[n];
    for(int i=0;i<n;i++) G[i]=NULL,G`[i]=NULL;
    while(m--)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        G[u-1]=newedge(G[u-1],v-1);
        G`[v-1]=newedge(G`[v-1],u-1);
    }
    int c1=0,c2=0;
    for(int i=0;i<n;i++)
    {
        if(!G[i]) c1++;
        if(!G`[i]) c2++;
    }   
    printf("%d",max(c1,c2));    
}