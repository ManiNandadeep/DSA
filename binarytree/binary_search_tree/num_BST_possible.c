#include<stdio.h>
#include<stdlib.h>
long long int fact(int n)
{
    long long int res=1;
    for(int i=1;i<=n;i++)
        res*=i;
    return res;
}
long long int countBST(int n)
{
    return fact(2*n)/(fact(n)*fact(n+1));
}
long long int countBT(int n)
{
    return fact(2*n)/fact(n+1);
}
int main(void)
{
    long long int no_bst,no_bt;
    int n;
    scanf("%d",&n);
    no_bst=countBST(n);
    no_bt=countBT(n);
    printf("Number of BST's possible are:");
    printf("%lld\n",no_bst);
    printf("Number of BT's possible are:");
    printf("%lld\n",no_bt);
    return 0;
}