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
char* findmultiply(char*num1,char*num2)
{
	int len1=strlen(num1),len2=strlen(num2);
	int i_n1=0,i_n2=0,i,j,n1,n2;
    char*res=malloc(10000*sizeof(char));
	int *result=malloc(10000*sizeof(char));
	for(i=len1-1;i>=0;i--)
	{
		int carry=0;
		i_n2=0;
		n1=num1[i]-'0';
		for(j=len2-1;j>=0;j--)
		{
			n2=num2[j]-'0';
			int sum=n1*n2+result[i_n1+i_n2]+carry;
			carry=sum/10;
			result[i_n1+i_n2]=sum%10;
			i_n2++;
		}
		if(carry)
		{
			result[i_n2+i_n1]+=carry;
		}
		i_n1++;
	}
    int count=len1+len2-1;
    while(result[count]==0)
    {
        count--;
    }
    for(int k=count,j=0;k>=0;k--,j++)
    {
        res[j]=result[k]+'0';
    }
    return res;
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
char* power(char*x,char*n)
{
    char*bin=malloc(10000*sizeof(char));
    bin=dec_to_bin(n);
    char*final=malloc(10000*sizeof(char));
    final[0]='1';
    int i;
    int size=strlen(bin);
    for(i=size-1;i>=0;i--)
    {
        if(bin[i]=='1')
        {
            final=findmultiply(final,x);
        }
        x=findmultiply(x,x);
    }
    free(bin);
    int size1=strlen(final);
    return final;
}
int main(void)
{
    char*x=malloc(1000*sizeof(char));
    char*n=malloc(1000*sizeof(char));
    scanf("%s %s",x,n);
    printf("%s",power(x,n));
    return 0;
}