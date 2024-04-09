#include <iostream> //https://www.luogu.com.cn/problem/P1706?contestId=83991 全排列问题
using namespace std;

int ha[11];
int a[11];

int n;

void dfs(int sum);

int main()
{
    for (int i = 0; i < 9; i++)
    {
        ha[i] = 1;
    }
    cin >> n;
    dfs(0);
    return 0;
}

void dfs(int sum)
{
    if (sum == n)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%5d", a[i]);
        }
        cout << endl;
        return;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (ha[i] == 1)
            {
                ha[i] = 0;
                a[sum] = i;
                dfs(sum + 1);
                ha[i] = 1;
            }
        }
    }
}