#include<stdio.h>
#include<Windows.h>
void swap(int &a,int &b)
{
	int temp=a;
	a=b;b=temp;
}
void bubleSort(int a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=n-1;j>=i+1;j--)
		{
			if(a[j]>a[j-1])
			swap(a[j],a[j-1]);
		}
	}
}
void out(int a[],int n)
{
	printf("\n");
	for(int i=0;i<n;i++)
	printf("%3d",a[i]);
}
void InsectionSort(int a[],int n)
{
	for(int i=1;i<n;i++)
	{
		int x=a[i];
		int pos=i-1;
		while(pos>=0&&x<a[pos])
		{
			a[pos+1]=a[pos];
			--pos;
		}
		a[pos+1]=x;
	}
}
void heapify(int a[],int pos,int n)
{
	int l=pos*2+1;
	int r=pos*2+2;
	int largest=pos;
	if(a[l]>a[largest]&&l<n)
		largest=l;
	if(a[r]>a[largest]&&r<n)
		largest=r;
	if(pos!=largest)
	{
		swap(a[largest],a[pos]);
		heapify(a,largest,n);		
	}		
}
void heapSort(int a[],int n)
{
	for(int i=n/2-1;i>=0;i--)
	{
		heapify(a,i,n);
	}
	for(int i=n-1;i>=0;i--)
	{
		swap(a[i],a[0]);
		heapify(a,0,i);
	}
}
int main()
{
	int a[100];
	int n=100;
	for(int i=0;i<n;i++)
	a[i]=rand()%100;
	bubleSort(a,n);
	out(a,n);
	
	return 0;
}
