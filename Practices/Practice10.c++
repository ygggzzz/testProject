#include <iostream> //https: //www.luogu.com.cn/problem/P5461 赦免战俘
#include <cmath>
using namespace std;

int m[1025][1025];
void fun(int a, int b, int c, int d);

int main()
{
    int n, k, i, j;
    cin >> n;
    k = pow(2, n);
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            m[i][j] = 1;
        }
    }
    fun(1, 1, k, k);
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            cout << m[i][j];
            if (j != k)
                cout << " ";
        }
        if (i != k)
        {
            cout << endl;
        }
    }
    return 0;
}

void fun(int a, int b, int c, int d)
{
    for (int i = a; i <= (a + c) / 2; i++)
    {
        for (int j = b; j <= (b + d) / 2; j++)
        {
            m[i][j] = 0;
        }
    }
    if (a == (a + c) / 2)
    {
        return;
    }
    fun((c + a + 1) / 2, b, c, (d + b - 1) / 2);
    fun(a, (d + b + 1) / 2, (c + a - 1) / 2, d);
    fun((c + a + 1) / 2, (d + b + 1) / 2, c, d);
}