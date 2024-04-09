#include <bits/stdc++.h>
using namespace std;
#define maxn 2000 + 5
#define inf INT_MAX / 3
int a[maxn][maxn], f[maxn][maxn];
int n, m, ans = inf;
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
            scanf("%d", &a[j][i]); // 注意此处的坑点，由于我们是n先，所以要反过来存
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (j == 1)
            {
                f[i][j] = min(f[i - 1][j], f[i - 1][m]) + a[i][j]; // 特殊的情况
            }
            else
            {
                f[i][j] = min(f[i - 1][j], f[i - 1][j - 1]) + a[i][j]; // 普通情况
            }
        }
    }
    for (int i = 1; i <= m; ++i)
        ans = min(ans, f[n][i]); // 答案即在最小的f[n][i]
    printf("%d", ans);
    return 0;
}
