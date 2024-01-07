//#include<bits/stdc++.h>
//using namespace std;
//void heapify(int a[],int n,int i)
//{
//	int largest=i;
//	int left=2*i+1;
//	int right=2*i+2;
//	if(left<n&&a[left]>a[largest])
//	largest=left;
//	if(right<n&&a[right]>a[largest])
//	largest=right;
//	if(largest!=i)
//	{
//		swap(a[i],a[largest]);
//		heapify(a,n,largest);
//	}
//}
//void heapsort(int a[],int n)
//{
//	//build max heap
//	for(int i=n/2-1;i>=0;i--)
//		heapify(a,n,i);
//	for(int i=n-1;i>=0;i--)
//	{
//		swap(a[0],a[i]);
//		heapify(a,i,0);		
//	}
//	
//	
//}
//int main()
//{
//	int a[100];
//	int n=50;
//	for(int i=0;i<n;i++)
//	a[i]=rand()%50;
//	heapsort(a,n);
//	for(int i=0;i<n;i++)
//	cout<<a[i]<<"  "; 
//	return 0;
//}
#include<stdio.h>
#include<Windows.h>
#include<time.h>
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void heapify(int a[],int m,int n)
{
	int l=m*2+1;
	int r=m*2+2;
	int largest=m;
	if(a[l]<a[largest]&&l<n)
	{
		largest=l;
	}
	if(a[r]<a[largest]&&r<n)
	{
		largest=r;
	}
	if(m!=largest)
	{
	swap(&a[m],&a[largest]);
	heapify(a,largest,n);
	}
}

void heapsort(int a[],int n)
{
	for(int i=n/2-1;i>=0;i--)
	heapify(a,i,n);
	for(int i=n-1;i>=0;i--)
	{
		swap(&a[0],&a[i]);
		heapify(a,0,i);
	}
}
int main()
{
	int a[100];
	for(int i=0;i<50;i++)
		a[i]=rand()%100;
	heapsort(a,50);
	for(int i=0;i<50;i++)
	printf("%4d",a[i]);
	
	return 0;
}

