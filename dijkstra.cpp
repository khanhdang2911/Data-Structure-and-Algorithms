#include<stdio.h>
int n,m,s,t;
int a[1000][1000];
const int INF=1e9;
void init()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[i][j]=0;
		}
	}
}
void nhap()
{
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		a[x][y]=w;
	}
}
void dijkstra()
{
	int dist[n];
	bool visited[n];
	int previous[n];
	for(int i=1;i<=n;i++)
	{
		dist[i]=INF;
		visited[i]=false;
		previous[i]=-1;
	}
	
	dist[s]=0;
	for(int count=0;count<n-1;count++)
	{
		int min=INF;
		int u=-1;
		for(int i=1;i<=n;i++)
		{
			if(dist[i]<min&&visited[i]==false)
			{
			min=dist[i];
			u=i;
			}
		}
		visited[u]=true;		
		for(int v=1;v<=n;v++)
		{
			if(visited[v]==false&&a[u][v]!=0&&dist[u] != INF&&(dist[u]+a[u][v]<dist[v]))
			{
				dist[v]=dist[u]+a[u][v];
				previous[v]=u;
			}
		}
	}
	printf("\nDo dai duong di la:%d",dist[t]);
	printf("\nDuong di ngan nhat: ");
	int path[100];
	int length=0;
	int temp=t;
	while(temp!=-1)
	{
		path[length++]=temp;
		temp=previous[temp];
	}
	for(int i=length-1;i>=0;i--)
	{
		if(path[i]==1)
		printf("%c",'A');
		if(path[i]==2)
		printf("%c",'B');
		if(path[i]==3)
		printf("%c",'C');
		if(path[i]==4)
		printf("%c",'D');
		if(path[i]==5)
		printf("%c",'E');
		if(path[i]==6)
		printf("%c",'F');
		if(path[i]==7)
		printf("%c",'G');
		if(i!=0)
		printf("->");
	}
}
int main()
{
	printf("Cac dinh tuong ung:\n");
	printf("1:A,2:B,3:C,4:D,5:E,6:F,7:G\n");
	printf("Nhap so dinh, so canh, dinh bat dau, dinh ket thuc:");
	scanf("%d %d %d %d",&n,&m,&s,&t);
	init();       
	nhap();
	dijkstra();
	
	return 0;
}
