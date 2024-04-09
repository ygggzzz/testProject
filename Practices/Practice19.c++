#include <iostream> //https://www.luogu.com.cn/problem/P2840 纸币问题2
using namespace std;
int n, w, a[1005], f[10005];
const int mod = 1e9 + 7;
int main()
{
    cin >> n >> w;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    f[0] = 1;
    for (int i = 1; i <= w; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i - a[j] >= 0)
            {
                f[i] = (f[i] + f[i - a[j]]) % mod;
            }
        }
    }
    cout << (f[w] % mod) << endl;
    return 0;
}