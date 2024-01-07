#include<stdio.h>
int a[100];
int n;
void out()
{
	for(int j=1;j<=n;j++)
	printf("%d",a[j]);
	printf("\n");
}
void Try(int i)
{
	for(int j=0;j<=1;j++)
	{
		a[i]=j;
		if(i==n)
		out();
		else
		Try(i+1);
	}
}
int main()
{	scanf("%d",&n);
	Try(1);
	return 0;
}
