#include<stdio.h>
#include<Windows.h>
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void bubleSort(int a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])swap(&a[j+1],&a[j]);
		}
	}
}
void insectionSort(int a[],int n)
{
	for(int i=1;i<n;i++)
	{
		int x=a[i];
		int pos=i-1;
		while(x<a[pos])
		{
			a[pos+1]=a[pos];
			--pos;
		}
		a[pos+1]=x;
	}
}
bool binarySearch(int a[],int n,int x)//tim phan tu x
{
	int left=0;
	int right=n-1;
	while(left<=right)
	{
		int mid=(left+right)/2;
		if(x>a[mid])
		left=mid+1;
		else right=mid-1;
		if(a[mid]==x)
		return true;
	}
	return false;
}

int main()
{
	int a[1000];
	int n=50;
	for(int i=0;i<n;i++)
	a[i]=rand()%100;
	insectionSort(a,n);
	for(int i=0;i<n;i++)
	{
		printf("%3d",a[i]);
	}
	if(binarySearch(a,n,111))
	printf("\nFound");
	return 0;
}
