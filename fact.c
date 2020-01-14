#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int multiply(int *result,int x,int res_size)
{
	int carry=0;
	for(int i=0;i<res_size;i++)
	{
		carry=carry+result[i]*x;
		result[i]=carry%10;
		carry=carry/10;
	}
	while(carry)
	{
		result[res_size]=carry%10;
		carry=carry/10;
		res_size++;
	}
	return res_size;
}
void factorial(int n)
{
	int *result=malloc(10000*sizeof(char));
	int res_size=1;
	result[0]=1;
	for(int x=2;x<=n;x++)
	{
		res_size=multiply(result,x,res_size);
	}
	for(int i=res_size-1;i>=0;i--)
	{
		printf("%d",result[i]);
	}
	free(result);
}
int main(void)
{
	clock_t start,end;
	double cpu_time_used;
	start=clock();
	int num;
	scanf("%d",&num);
	factorial(num);
	end=clock();
	cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
	printf("\n%lf",cpu_time_used);
	return 0;
}
