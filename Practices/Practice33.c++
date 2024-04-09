#include <iostream> //https://www.luogu.com.cn/problem/P1605?contestId=83991 迷宫
using namespace std;

int n, m, t;
int sx, sy, fx, fy;
int a[10][10];
int sum = 0;

void dfs(int x, int y);

int main()
{
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            a[i][j] = 0;
        }
    }
    cin >> sx >> sy >> fx >> fy;
    if (sx > fx)
    {
        int tmp = sx;
        sx = fx;
        fx = tmp;
    }
    if (sy > fy)
    {
        int tmp = sy;
        sy = fy;
        fy = tmp;
    }
    int bx, by;
    for (int i = 0; i < t; i++)
    {
        cin >> bx >> by;
        a[bx][by] = 1;
    }
    dfs(sx, sy);
    cout << sum;
}

void dfs(int x, int y)
{
    if (x == 0 || x > n || y == 0 || y > m)
    {
        return;
    }
    if (a[x][y] == 1)
    {
        return;
    }
    if (x == fx && y == fy)
    {
        sum++;
        return;
    }
    a[x][y] = 1;
    dfs(x - 1, y);
    dfs(x + 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
    a[x][y] = 0;
}