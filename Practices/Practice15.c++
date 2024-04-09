#include <iostream> //https://www.luogu.com.cn/problem/P2196 挖地雷
using namespace std;

int b[25];
int a[25];
int h[25][25];
int dp[25];
int fre[30], ans[30];
int sum, s, t;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[i] = a[i];
        fre[i] = i;
        if (sum < dp[i])
        {
            s = i;
        }
        sum = max(sum, dp[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            cin >> h[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (h[i][j] == 0)
            {
                continue;
            }
            if (dp[j] < dp[i] + a[j])
            {
                fre[j] = i;
            }
            dp[j] = max(dp[j], dp[i] + a[j]);
            if (sum < dp[j])
            {
                s = j;
            }
            sum = max(sum, dp[j]);
        }
    }
    int i = s;
    while (fre[i] != i)
    {
        t++;
        ans[t] = i;
        i = fre[i];
    }
    t++;
    ans[t] = i;
    for (int i = t; i >= 1; i--)
    {
        cout << ans[i] << " ";
    }
    cout << endl
         << sum;
    return 0;
}