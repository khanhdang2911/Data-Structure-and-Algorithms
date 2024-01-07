#include<bits/stdc++.h>
using namespace std;
int a[100], used[100], t[100];
int n;
void out()
{
	for(int j=1;j<=n;j++)
	printf("%3d",t[j]);
	printf("\n");
}
void Try(int i)
{
	for(int j=0;j<n;j++)
	{
		if(!used[a[j]])
		{
		t[i]=a[j];
		used[a[j]]=1;
		if(i==n)
		out();
		else
		Try(i+1);
		used[a[j]]=0;
	 }
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	Try(1);  
	return 0;
}
