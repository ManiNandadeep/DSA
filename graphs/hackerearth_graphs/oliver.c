#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#define ll long long
struct List{
    ll int i;
    struct List*next; 
};

struct List *
newedge (struct List *node, ll int i)
{
  struct List *temp = (struct List *) malloc (sizeof (struct List));
  temp->i = i;
  temp->next = node;
  return temp;
}

void
iDFS (struct List *list[], ll int s, ll int n)        //dfs with discovery time and finish time -iterative method
{
  bool V[n];
  ll int i, d[n], f[n], c = 1;
  for (i = 0; i < n; ++i)
    {
      V[i] = false;
      f[i] = 0;
    }

  struct List *head = (struct List *) malloc (sizeof (struct List));
  head->i = s;
  head->next = NULL;
  struct List *temp, *t1, *h1;
  while (head)
    {
      if (!V[head->i])
	{
	  V[head->i] = true;
	  temp = list[head->i];
	  d[head->i] = c++;
	  if (temp)
	    {
	      h1 = head;
	      // head = head->next;
	      while (temp)
		{
		  if (!V[temp->i])
		    {
		      head = newedge (head, temp->i);
		    }


		  temp = temp->next;
		}


	    }
	  else
	    {
	      if (!f[head->i])
		f[head->i] = c++;
	      head = head->next;
	    }
	}
      else
	{
	  if (!f[head->i])
	    f[head->i] = c++;
	  head = head->next;
	}

    }
    ll int q;
    scanf("%lld",&q);
    while (q--)
    {
        ll int Q,x,y;
        scanf("%lld %lld %lld",&Q,&x,&y);
        if(Q==0)
        {
            if(d[y-1]>d[x-1]&&f[y-1]<f[x-1])
                printf("YES\n");
            else printf("NO\n");
        }
        if(Q==1)
        {
            if(d[y-1]<d[x-1]&&f[y-1]>f[x-1])
                printf("YES\n");
            else printf("NO\n");
        }
    }
    
}
int main()
{
    ll int n;
    scanf("%lld",&n);
    struct List*list[n];
    for(ll int i=0;i<n;i++) list[i]=NULL;
    ll int m=n-1;
    while(m--)
    {
        ll int u,v;
        scanf("%lld %lld",&u,&v);
        list[u-1]=newedge(list[u-1],v-1);
        list[v-1]=newedge(list[v-1],u-1);
    }    
    iDFS(list,0,n);
}