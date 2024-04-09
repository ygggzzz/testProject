#include <iostream> //https://www.luogu.com.cn/problem/P1028?contestId=83991 数的计算
using namespace std;

int n, res;
int f[1001];
// void dfs(int n);

int main()
{
    cin >> n;
    f[1] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i / 2; j++)
        {
            f[i] += f[j];
        }
        if (i > 1)
        {
            f[i]++;
        }
    }
    cout << f[n];
    return 0;
}
