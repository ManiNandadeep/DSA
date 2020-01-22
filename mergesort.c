#include<stdio.h>
#include<stdlib.h>
void printsorted(int arr[],int n)
{
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
}
void merge(int arr[],int first,int mid,int last)
{
    int i,j,k;
    int temp1=mid-first+1;
    int temp2=last-mid;
    int left[temp1],right[temp2];
    for(i=0;i<temp1;i++)
        left[i]=arr[first+i];
    for(j=0;j<temp2;j++)
        right[j]=arr[mid+1+j];
    i=0;
	j=0;
	k=first;
	while(i<temp1 && j<temp2){
		if(left[i]<=right[j]){
                        arr[k]=left[i];
                        i++;
                }
		else{
                        arr[k]=right[j];
                        j++;
                }

		k++;
	}
	while(i<temp1){
		arr[k]=left[i];
		i++;
		k++;
	}
	while(j<temp2){
		arr[k]=right[j];
		j++;
		k++;
	}
}
void mergesort(int arr[],int first,int last)
{
    int mid;
    if(first<last)
    {
        mid=first+(last-first)/2;
        mergesort(arr,first,mid);
        mergesort(arr,mid+1,last);
        merge(arr,first,mid,last);
    }
}
int main(void)
{
    int*arr=malloc(100*sizeof(char));
    int n;
    scanf("%d\n",&n);
    scanf("%d",&arr[0]);
    for(int i=1;i<n;i++)
        scanf(",%d",&arr[i]);
    mergesort(arr,0,n-1);
    printsorted(arr,n);
    return 0;
}