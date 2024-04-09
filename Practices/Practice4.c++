#include <iostream> //https://www.luogu.com.cn/problem/P1060 开心的金明
using namespace std;

int dp[100001];
int a[100001], b[100001];
int res = 0;

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = n; j >= 0; j--)
        {
            if (j >= a[i])
            {
                dp[j] = max(dp[j], dp[j - a[i]] + a[i] * b[i]);
            }
        }
    }
    cout << dp[n];
}