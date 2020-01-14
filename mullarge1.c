#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void findmultiply(char*num1,char*num2)
{
	int len1=strlen(num1),len2=strlen(num2);
	int i_n1=0,i_n2=0,i,j,n1,n2;
	int *result=malloc(255*sizeof(int));
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
	for(int k=len1+len2-1;k>=0;k--)
	{
		printf("%d",result[k]);
	}
}
int main(void)
{
	char*num1=malloc(255*sizeof(char));
	char*num2=malloc(255*sizeof(char));
	scanf("%s %s",num1,num2);
	findmultiply(num1,num2);
	return 0;
}
