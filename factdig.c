#include<stdio.h>
#include<math.h>
int no_dig_fact(int num)
{
    double result=0;
    for(int i=2;i<=num;i++)
    {
        result+=log10(i);
    }
    return floor(result)+1;
}
int main(void)
{
    int num;
    scanf("%d",&num);
    printf("%d",no_dig_fact(num));
    return 0;
}