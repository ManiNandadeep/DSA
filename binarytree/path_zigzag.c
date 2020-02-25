#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int*pathInZigZagTree(int label,int *returnSize)
{
    int base=1;
    int count=1;
    int *result;
    int bak=label;
    int i,idx=0;
    while(label>=base)
    {
        label-=base;
        base*=2;
        count++;
    }
    if (label==0)
        count--;
    label=bak;
    result=(int*)malloc(count*sizeof(int));
    for(i=count-1;i>0;i--)
    {
        result[i]=label;
        idx=(label-pow(2,i))/2;
        label=pow(2,i)-1-idx;
    }
    result[0]=1;
    *returnSize=count;
    return result;
}
int main(void)
{
    int label;
    scanf("%d",&label);
    int returnSize;
    int *path=malloc(1000*sizeof(int));
    path=pathInZigZagTree(label,&returnSize);
    for(int i=0;i<returnSize;i++)
    {
        printf("%d ",path[i]);
    }
    return 0;
}