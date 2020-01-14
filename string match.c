#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(void)
{
    char*text=malloc(255*sizeof(char));
    char*pat=malloc(255*sizeof(char));
    scanf("%s %s",text,pat);
    int n=strlen(text),m=strlen(pat),i,j;
    for(i=0;i<=n-m;i++)
    {
        for(j=0;j<m;j++)
        {
            if(text[i+j]!=pat[j])
                break;
        }
        if(j==m)
        {
            printf("There is a match at %d\n",i);
        }
    }  
    return 0;  
}