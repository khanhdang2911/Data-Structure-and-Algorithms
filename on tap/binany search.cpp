#include<stdio.h>
int BinarySearch(int a[],int n,int element)
{
	int r=n-1;
	int l=0;
	while(true)
	{
		int mid=(r+l)/2;
		if(a[mid]==element)
		return 1;
		if(element>a[mid])
		l=mid+1;
		else if(element<a[mid])
		r=mid-1;
		if(l>r)
		return 0;
	}
}
int main()
{
	int a[100];
	int n=11;
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("\n%d",BinarySearch(a,n,1));
	return 0;
}
