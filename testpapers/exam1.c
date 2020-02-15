#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int n,l,i,j,min,max,count=0;
    scanf("%d %d\n",&n,&l);
    int *a=malloc(n*sizeof(char));
    scanf("%d",&a[0]);
    for(i=1;i<n;i++)
        scanf(" %d",&a[i]);
    for(i=0;i<n;i++)
    {
       max=a[i];
       min=a[i];
       for(j=i;j<n;j++)
       {
            if(a[j]<min)
                min=a[j];
            if(a[j]>max)
                max=a[j];
            if(max-min==(j-i) && j-i+1>=l)
                count++;
       }
    }
    printf("%d",count);
    return 0;
}