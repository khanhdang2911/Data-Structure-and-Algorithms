#include<stdio.h>

int parent[1001];
int n,m;
struct canh{
	int u,v;
	int w;//trong so cua do thi
};
canh edge[1000];
void make_set()
{
	for(int i=1;i<=n;i++)
	{
		parent[i]=i;
	}
}
int find(int v)
{
	if(parent[v]==v)
	return v;
	else
	return parent[v]=find(parent[v]);
}
bool Union(int a,int b)
{
	a=find(a);
	b=find(b);
	if(a==b)
		return false;
	parent[b]=a;
	return true;
}
void input()
{
	printf("Nhap so dinh va so canh:");
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int x,y,m;
		scanf("%d %d %d",&x,&y,&m);
		edge[i].u=x;
		edge[i].v=y;
		edge[i].w=m;
	}
}
void swap(canh &a,canh &b)
{
	canh temp=a;
	a=b;
	b=temp;
}
void Sort()
{
	for(int i=0;i<m-1;i++)
	{
		for(int j=i+1;j<m;j++)
		{
			if(edge[i].w>edge[j].w)
			swap(edge[i],edge[j]);
		}
	}
}
void kruskal()
{
	canh caykhungMin[1000];
	int size=0;
	Sort();
	for(int i=0;i<m;i++)
	{
		if(Union(edge[i].u,edge[i].v)==true)
		{
			caykhungMin[size]=edge[i];
			size++;
		}
	}
	int d=0;
	for(int i=0;i<size;i++)
	{
		d+=caykhungMin[i].w;
	}
	printf("\nTong trong so:%d",d);
	for(int i=0;i<size;i++)
	{
		printf("\n%d %d %d ",caykhungMin[i].u,caykhungMin[i].v,caykhungMin[i].w);
	}
	
}

int main()
{
	input();
	make_set();
	kruskal();
	return 0;
}
