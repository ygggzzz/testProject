#include <iostream> //https://www.luogu.com.cn/problem/P1157?contestId=83991 组合的输出
#include <iomanip>
#include <algorithm>
using namespace std;

int n, r;
int a[101];

void dfs(int t);

int main()
{
    cin >> n >> r;
    dfs(0);
    return 0;
}

void dfs(int t)
{
    if (t == r)
    {
        for (int i = 1; i <= r; i++)
        {
            cout << setw(3) << a[i];
        }
        cout << endl;
        return;
    }
    for (int i = a[t] + 1; i <= n; i++)
    {
        a[t + 1] = i;
        dfs(t + 1);
    }
}