#include<stdio.h>
const int INF=1e9;
int a[1000][1000],n,m,s,t;
void nhap()
{
	printf("Nhap so dinh, so canh, dinh dau, dinh cuoi:");

	scanf("%d%d%d%d",&n,&m,&s,&t);

	printf("Nhap thong tin cho canh:\n");
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		a[x][y]=w;
	}
}
void Dijkstra()
{
	int dist[1000];
	int previous[1000];
	bool used[1000];
	for(int i=1;i<=n;i++)
	{
		dist[i]=INF;
		previous[i]=-1;
		used[i]=false;	
	}
	dist[s]=0;
	for(int j=1;j<=n;j++)
	{
		int u=-1;
		int min=INF;
		for(int i=1;i<=n;i++)
		{
			if(dist[i]<min&&used[i]==false)
			{
				min=dist[i];
				u=i;
			}
		}
		used[u]=true;//danh dau da duoc su dung
		for(int v=1;v<=n;v++)
		{
			if(used[v]==false&&a[u][v]!=0&&(dist[u]+a[u][v]<dist[v]))
			{
				dist[v]=dist[u]+a[u][v];
				previous[v]=u;
			}
		}
  	}
	int path[1000];
	int size=0;
	int temp=t;
	while(temp!=-1)
	{
		path[size++]=temp;
		temp=previous[temp];
	}
	printf("\nDuong di tu dinh %d den dinh %d ngan nhat la:",s,t);
	for(int i=size-1;i>=0;i--)
	{
		printf("%3d",path[i]);
	}
}
int main()
{
	nhap();
	Dijkstra();
	
	return 0;
}
