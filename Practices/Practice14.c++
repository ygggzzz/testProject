#include <iostream> //https://www.luogu.com.cn/problem/P1216 数字三角形
#include <cmath>
using namespace std;
int a[1001][1001];
int sum[1001][1001];
int main()
{
    int r;
    cin >> r;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= r; i++)
    {
        sum[r][i] = a[r][i];
    }
    for (int i = r - 1; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            sum[i][j] = max(sum[i + 1][j], sum[i + 1][j + 1]) + a[i][j];
        }
    }
    cout << sum[1][1];
    return 0;
}