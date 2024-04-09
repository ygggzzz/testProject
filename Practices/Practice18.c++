#include <iostream> //https://www.luogu.com.cn/problem/P2842 纸币问题 1
using namespace std;

int dp[10001];

int main()
{
    int n, w;
    int a[1001];
    int cost;
    cin >> n >> w;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= w; i++)
    {
        cost = 0x3f3f3f3f;
        for (int j = 0; j < n; j++)
        {
            if (i >= a[j])
            {
                cost = min(cost, dp[i - a[j]]);
            }
        }
        dp[i] = cost + 1;
    }
    cout << dp[w];
    return 0;
}