#include<bits/stdc++.h>
using namespace std;

int a[100],n;
vector<int>b;
void out(int m)
{

  for(int i=0;i<b.size();i++)
  cout<<b[i]<<" ";
  cout<<endl;
}
void Try(int index,int m)
{
	if(index==n)
	return ;
	for(int i=index;i<n;i++)
	{
		b.push_back(a[i]);
			int sum=0;
         for(int j=0;j<b.size();j++)
         sum+=b[j];
         if(sum==m)
         out(m);
		Try(i+1,m);
		b.pop_back();
	}
}
int main()
{
	int m;
	scanf("%d",&m);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	Try(0,m);
	return 0;
}
