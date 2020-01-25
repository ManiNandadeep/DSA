#include<stdio.h>
int findpower(int x,int n)
{
    int y=1;
    while(n>0)
    {
        if(n%2==1)
            y=y*x;
        x=x*x;
        n=n/2;
    }
    return y;
}
int main(void)
{
    int x,n;
    scanf("%d %d",&x,&n);
    int p=findpower(x,n);
    printf("%d",p);
    return 0;
}