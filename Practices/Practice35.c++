#include <iostream>

using namespace std;
int a[10001], dp[50001];
int main()
{
    int v, n;
    cin >> v >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = v; j >= a[i]; j--)
        {
            dp[j] = max(dp[j - a[i]] + a[i], dp[j]);
        }
    }
    cout << v - dp[v];
}