#include <stdio.h>
void main(){
	int i,j,k,n,s;
	n=10000;s=2;
	for (i=0;i<n;++i)
		for (j=0;j<n;++j)
			for (k=0;k<n;++k)
				s=2*s+1;
	printf("%d",s);
}