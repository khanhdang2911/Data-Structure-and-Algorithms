#include<stdio.h>
#define k 1000
#define max 100
int find(int a[],int n,int l,int r)
{
	int count [k];
	
	for(int i=0;i<k;i++)
	count[i]=0;
	
	for(int i=0;i<n;i++)
	count[a[i]]++;
	
	for(int i=1;i<k;i++)
	count[i]+=count[i-1];
		
	return count[r]-count[l-1];
}

int main()
{
	int a[max]={3,1,3,2,4,7,5};
	int res=find(a,7,1,3);
	printf("%d",&res);
	return 0;
}
