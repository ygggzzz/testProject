#include <iostream> //https://www.luogu.com.cn/problem/P1077 摆花
using namespace std;

int main()
{
    int num[1001];
    int a[1001][1001];
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
    }
    for (int i = 0; i <= num[1]; i++)
    {
        a[1][i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        a[i][0] = 1;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = 0; k <= num[i] && k <= j; k++)
            {
                a[i][j] = (a[i][j] + a[i - 1][j - k]) % 1000007;
            }
        }
    }
    cout << a[n][m];
    return 0;
}
