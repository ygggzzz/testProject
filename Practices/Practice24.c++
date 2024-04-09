#include <iostream> //https://www.luogu.com.cn/problem/P2404?contestId=83991 自然数的拆分问题
using namespace std;

int n, ans, a[10] = {1};

void dfs(int s);

int main()
{
    cin >> n;
    dfs(1);
    return 0;
}

void dfs(int s)
{
    for (int i = a[s - 1]; i < n; i++)
    {
        if (ans + i <= n)
        {
            ans += i;
            a[s] = i;

            if (ans == n)
            {
                for (int j = 1; j < s; j++)
                {
                    cout << a[j] << "+";
                }
                cout << a[s] << endl;
            }
            else
            {
                dfs(s + 1);
            }
            ans -= i;
        }
    }
}