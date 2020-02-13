#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    //int*a=malloc(255*sizeof(char));
    //int n;
    // scanf("%d\n",&n);
    // scanf("%d",&a[0]);
    // for(int i=1;i<n;i++)
    //     scanf(" %d",&a[i]);
    int a[]={6,8,11,14,10,13,9,7,1,3,2};
    int n=sizeof(a) / sizeof(a[0]);
    printf("%d",n);
    int*s=malloc(255*sizeof(char));
    int*b=malloc(n*sizeof(char));
    int top=-1,i;
    printf("%d",top);
    printf("\n");
    for(i=0;i<n;i++)
    {
        if(top<0) s[++top]=i;
        else if(a[s[top]]<a[i]) s[++top]=i;
        else {
            while (top>=0 &&a[s[top]]>=a[i])
            {
                b[s[top--]]=i;
            }
            s[++top]=i;
        }
    }
    while(top>=0)
        b[s[top--]]=-1;
    for(int i=0;i<n;i++)
        printf("%d ",b[i]);
    return 0;    
}