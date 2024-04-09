#include <iostream> //https://www.luogu.com.cn/problem/P1754?contestId=83991 球迷购票问题
using namespace std;

int f[101][101];
int n;
int res = 0;

void dfs(int i, int j); // 50i 100j

int main()
{

    cin >> n;
    dfs(0, 0);
    cout << res;
}

void dfs(int i, int j)
{
    if (i == n && j == n)
    {
        res++;
    }
    if (j > i || j > n || i > n)
    {
        return;
    }
    if (i == j)
    {
        dfs(i + 1, j);
    }
    else
    {
        dfs(i + 1, j);
        dfs(i, j + 1);
    }
}
