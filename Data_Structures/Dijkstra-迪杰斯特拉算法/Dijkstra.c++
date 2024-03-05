#include <iostream> //处理有向无环图 距离为非负数
using namespace std;
const int inf = 0x7fffffff;
int n, e, s;
int dis[101], check[101];
int graph[101][101];
int main()
{
    for (int i = 1; i <= 100; i++)
    {
        dis[i] = inf;
    }
    cin >> n >> e; // n多少点 e多少组线
    for (int i = 1; i <= e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c; // a到b距离c
    }
    cin >> s; // 原点
    dis[s] = 0;
    for (int i = 1; i <= n; i++)
    {
        int minn = inf, minx;
        for (int j = 1; j <= n; j++)
        {
            if (dis[j] < minn && check[j] == 0)
            {
                minn = dis[j];
                minx = j; // 记录这个点的编号
            }
        }
        check[minx] = 1;
        for (int j = 1; j <= n; j++)
        {
            if (graph[minx][j] > 0)
            {
                if (minn + graph[minx][j] < dis[j])
                {
                    dis[j] = minn + graph[minx][j];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
    }
    return 0;
}
