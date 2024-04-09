#include <iostream> //https: //www.luogu.com.cn/problem/U245446?contestId=83991 数的拆分
using namespace std;

int a[10001];
// int res = 0;

void dfs(int t, int left);

int main()
{
    int n;
    cin >> n;
    dfs(0, n);
    // cout << res;
    return 0;
}

void dfs(int t, int left)
{
    int i;
    if (left == 0)
    {
        // res++;
        cout << a[0];
        for (int i = 1; i < t; i++)
        {
            cout << "+" << a[i];
        }
        cout << endl;
    }
    else
    {
        for (int i = 1; i <= left; i++)
        {
            a[t] = i;
            dfs(t + 1, left - i);
        }
    }
}