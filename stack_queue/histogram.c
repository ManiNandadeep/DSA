#include<stdio.h>
#include<stdlib.h>
int isEmpty(int*s)
{
    if(sizeof(s)==0)
        return 1;
    return 0;
}
int getMaxArea(int hist[],int n)
{
    int st[n+1],top=0;
    int ts;
    int max_area=0;
    int new_area;
    int i=0;
    while(i<n)
    {
        if((top==0) || hist[st[top-1]]<=hist[i])
        {
            st[top]=i++;
            top++;
        }
        else
        {
            ts=st[--top];
            if(top>0) new_area=hist[ts]*(i-st[top-1]-1);
            else new_area=hist[ts]*i;
            if(max_area<new_area) max_area=new_area;
        }
    }
    while(top>0)
    {
        ts=st[--top];
        if(top>0) new_area=hist[ts]*(i-st[top-1]-1);
        else new_area=hist[ts]*i;
        if(max_area<new_area) max_area=new_area;
    }
    return max_area;
}
int main(void)
{
    int hist[]={1,2,3,2};
    int n=sizeof(hist)/sizeof(hist[0]);
    printf("%d",getMaxArea(hist,n));
    return 0;
}