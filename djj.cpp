#include <stdio.h>
#include <stdbool.h>

const int INF = 1e9;
int a[1000][1000], n, m;
int s, t;

void nhap()
{
    printf("Nhap so dinh, so canh, dinh dau, dinh cuoi: ");
    scanf("%d%d", &n, &m);
    getchar(); // Ð?c ký t? newline còn sót l?i trong buffer

    printf("Nhap thong tin cho canh:\n");
    for (int i = 1; i <= m; i++)
    {
        char x, y;
        int w;
        scanf(" %c %c %d", &x, &y, &w);
        a[x - 'A'][y - 'A'] = w;
    }

    char start, end;
    printf("Nhap dinh dau va dinh cuoi: ");
    scanf(" %c %c", &start, &end);
    s = start - 'A';
    t = end - 'A';
}

void Dijkstra()
{
    int dist[1000];
    int previous[1000];
    bool used[1000];
    for (int i = 0; i < n; i++)
    {
        dist[i] = INF;
        previous[i] = -1;
        used[i] = false;
    }
    dist[s] = 0;
    for (int j = 0; j < n; j++)
    {
        int u = -1;
        int min = INF;
        for (int i = 0; i < n; i++)
        {
            if (dist[i] < min && used[i] == false)
            {
                min = dist[i];
                u = i;
            }
        }
        used[u] = true;
        for (int v = 0; v < n; v++)
        {
            if (used[v] == false && a[u][v] != 0 && (dist[u] + a[u][v] < dist[v]))
            {
                dist[v] = dist[u] + a[u][v];
                previous[v] = u;
            }
        }
    }
    int path[1000];
    int size = 0;
    int temp = t;
    while (temp != -1)
    {
        path[size++] = temp;
        temp = previous[temp];
    }
    printf("\nDuong di tu dinh %c den dinh %c ngan nhat la: ", s + 'A', t + 'A');
    for (int i = size - 1; i >= 0; i--)
    {
        printf("%c ", path[i] + 'A');
    }
}

int main()
{
    nhap();
    Dijkstra();

    return 0;
}
