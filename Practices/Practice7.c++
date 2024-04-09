#include <iostream> //https://www.luogu.com.cn/problem/P1926 小书童——刷题大军
#include <algorithm>
using namespace std;

int main()
{
    int n, m, k, r;
    int sum = 0;
    int res = 0;
    int temp;
    cin >> n >> m >> k >> r;
    int a[1001], b[1001], c[1001];
    int dp[10001];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        // sum += b[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> c[i];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = r; j >= b[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - b[i]] + c[i]);
        }
    }
    // sort(dp, dp + sum);
    for (int i = 0; i < r; i++)
    {
        if (dp[i] >= k)
        {
            temp = i;
            break;
        }
    }
    r = r - temp;
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        if (r >= a[i])
        {
            res++;
            r -= a[i];
        }
        else
        {
            break;
        }
    }
    cout << res;
    return 0;
}