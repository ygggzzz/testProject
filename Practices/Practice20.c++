#include <iostream> //https://www.luogu.com.cn/problem/P2834 纸币问题 3
using namespace std;

const int mod = 1e9 + 7;

int main()
{
    int a[10001];
    int n, w;
    int dp[10001][10001]; // dp[i][j]只用前i张凑到j
    cin >> n >> w;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (j < a[i])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i][j - a[i]] + dp[i - 1][j];
                dp[i][j] %= mod;
            }
        }
    }
    cout << dp[n][w];
    return 0;
}