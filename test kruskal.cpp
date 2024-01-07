#include<stdio.h>
int parent[100],n,m;
struct canh{
	int u,v;
	int w;//trong so
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
	if(v==parent[v])
	return v;
	else
	parent[v]=find(parent[v]);
}
bool Union(int a,int b)
{
	a=find(a);
	b=find(b);
	if(a==b)
	return false;
	else{
		parent[a]=b;
		return true;
	}
}
void swap(canh&a,canh&b)
{
	canh temp=a;
	a=b;
	b=temp;
}
void Sort()
{
	for(int i=1;i<m;i++)
	{
		for(int j=i+1;j<m+1;j++)
		{
			if(edge[i].w>edge[j].w)
			swap(edge[i],edge[j]);
		}
	}
}
void input()
{
	printf("Nhap so dinh, so canh:");
	scanf("%d%d",&n,&m);
	printf("Nhap thong tin cho tung canh:\n");
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		edge[i].u=x;
		edge[i].v=y;
		edge[i].w=z;
	}
}
void kruskal()
{
	canh CayKhungNhoNhat[1000];
	int tongTrongSo=0;
	int size=0;
	Sort();
	for(int i=1;i<=n;i++)
	{
		if(Union(edge[i].u,edge[i].v)==true)
		{
			CayKhungNhoNhat[size++]=edge[i];
		}
	}
	for(int i=0;i<size;i++)
	{
		tongTrongSo+=CayKhungNhoNhat[i].w;
	}
	printf("\nTong trong so cua cay khung nho nhat:%d",tongTrongSo);
	printf("\nCac canh trong cay khung nho nhat la:\n");
	for(int i=0;i<size;i++)
	{
		printf("%3d%3d%3d\n",CayKhungNhoNhat[i].u,CayKhungNhoNhat[i].v,CayKhungNhoNhat[i].w);
	}
}
int main()
{
	input();
	make_set();
	kruskal();
	return 0;
}