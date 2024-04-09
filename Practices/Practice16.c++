#include <iostream> //https://www.luogu.com.cn/problem/P3842 线段
#include <cmath>
using namespace std;

const int maxn = 2e4 + 5;
int n;
int a[maxn][2], dp[maxn][2], b[maxn];

int dis(int x, int y)
{
    return abs(x - y);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i][0] >> a[i][1];
        b[i] = a[i][1] - a[i][0];
    }
    dp[1][1] = dis(a[1][1], 1);
    dp[1][0] = dis(a[1][1], 1) + b[1];
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = min(dp[i - 1][0] + b[i] + dis(a[i - 1][0], a[i][1]), dp[i - 1][1] + b[i] + dis(a[i - 1][1], a[i][1])) + 1;
        dp[i][1] = min(dp[i - 1][0] + b[i] + dis(a[i - 1][0], a[i][0]), dp[i - 1][1] + b[i] + dis(a[i - 1][1], a[i][0])) + 1;
    }
    cout << min(dp[n][0] + dis(n, a[n][0]), dp[n][1] + dis(n, a[n][1]));
}
