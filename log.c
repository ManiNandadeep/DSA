#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void reverse(char s[])
{
    int i, j;
    char c; 
    for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
void itoa(int n, char s[])
{
    int i, sign;
    if ((sign = n) < 0)  /* record sign */
        n = -n;          /* make n positive */
    i = 0;
    do {       /* generate digits in reverse order */
        s[i++] = n % 10 + '0';   /* get next digit */
    } while ((n /= 10) > 0);     /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
 reverse(s);
}
char*divide_by_two(char*n)
{
    char*quo=malloc(10000*sizeof(char));
    int idx=0;
    int temp=n[idx]-'0';
    while(temp<2)
    {
        temp=temp*10+(n[++idx]-'0');
    }
    while(strlen(n)>idx)
    {
        char s[10000];
        itoa(temp/2,s);
        quo=strcat(quo,s);
        temp=(temp%2)*10+n[++idx]-'0';
    }
    if(strlen(quo)==0)
    {
        return "0";
    }
    return quo;
}
char* dec_to_bin(char*n)
{
    int count=0;
    char* bin = malloc(10000*sizeof(char));
    while(n[0] != '0')
    {
        bin[count]=(n[strlen(n)-1]-'0')%2+'0';
        count++;
        n=divide_by_two(n);
    }
    reverse(bin);
    return bin;
}
int main(void)
{
    char*num=malloc(255*sizeof(char));
    char*bin=malloc(10000*sizeof(char));
    scanf("%s",num);
    bin=dec_to_bin(num);
    int log=strlen(bin)-1;
    printf("%d",log);
    return 0;
}