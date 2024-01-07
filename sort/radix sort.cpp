#include<stdio.h>
int a[100],h[100],s[100];
int n;
void radixSort()
{
	int max=a[0],k=1;
	for(int i=0;i<n;i++)
	{
	if(a[i]>max)
	max=a[i];	
	}
	while(max/k>0)
	{
		for(int i=0;i<100;i++)
		s[i]=0;
		for(int i=0;i<n;i++)
		s[(a[i]/k)%10]++;
		for(int i=1;i<100;i++)
		{
			s[i]+=s[i-1];
		}
		for(int i=n-1;i>=0;i--)
		{
		h[s[(a[i] / k) % 10]-1] = a[i];
		s[(a[i]/k)%10]--;
			}
			printf("kq:\n");
			for(int i=0;i<n;i++)
			printf("%5d",h[i]);
			printf("\n");
		k*=10;
		for (int i = 0; i < n; i++)
                a[i] = h[i];
	
	}		
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	radixSort();
	for(int i=0;i<n;i++)
	printf("%5d",a[i]);
	printf("\n");	
	return 0;
}

