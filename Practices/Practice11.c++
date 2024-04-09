#include <bits/stdc++.h> //https://www.luogu.com.cn/problem/P2437 蜜蜂路线 高精度加法
using namespace std;
int n, m, a[5005] = {1}, b[5005] = {1}, c[5005] = {1}, len = 1;
void f()
{
    int jw = 0;
    for (int i = 0; i < len; i++)
    {
        c[i] = a[i] + b[i] + jw;
        jw = c[i] / 10;
        c[i] = c[i] % 10;
    }
    if (jw != 0)
    {
        c[len] = jw;
        len++;
    }
    for (int i = 0; i < len; i++)
    {
        a[i] = b[i];
        b[i] = c[i];
    }
}
int main()
{
    cin >> m >> n;
    for (int i = 3; i <= n - m + 1; i++)
    {
        f();
    }
    for (int i = len - 1; i >= 0; i--)
    {
        cout << c[i];
    }
    return 0;
}