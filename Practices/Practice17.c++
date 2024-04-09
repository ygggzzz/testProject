#include <iostream> // https://www.luogu.com.cn/problem/P2392 kkksc03考前临时抱佛脚  要最小，需要a1，a2差最小，最好安排得一样
#include <climits>
using namespace std;

int a[21], b[21], c[21], d[21];
int n1, n2, n3, n4;
int sum1, sum2, sum3, sum4;
int a1, a2;
int minn = INT_MAX;
int res = 0;

void mintime(int *a, int n, int j);

int main()
{
    int sum = 0;
    cin >> n1 >> n2 >> n3 >> n4;
    for (int i = 0; i < n1; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n2; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < n3; i++)
    {
        cin >> c[i];
    }
    for (int i = 0; i < n4; i++)
    {
        cin >> d[i];
    }
    mintime(a, n1, 0);
    res += minn;
    a1 = 0;
    a2 = 0;
    minn = INT_MAX;
    mintime(b, n2, 0);
    res += minn;
    a1 = 0;
    a2 = 0;
    minn = INT_MAX;
    mintime(c, n3, 0);
    res += minn;
    a1 = 0;
    a2 = 0;
    minn = INT_MAX;
    mintime(d, n4, 0);
    res += minn;
    cout << res;
    return 0;
}

void mintime(int *a, int n, int j)
{
    if (j >= n)
    {
        minn = min(minn, max(a1, a2));
        return;
    }
    a1 += a[j];
    mintime(a, n, j + 1);
    a1 -= a[j];
    a2 += a[j];
    mintime(a, n, j + 1);
    a2 -= a[j];
}