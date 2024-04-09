#include <iostream> //https://www.luogu.com.cn/problem/P3853 路标设置
using namespace std;

int b[1000001];
int len, n, k;

bool check(int mid)
{
    int cnt = 0;
    for (int i = 2; i <= n; i++)
    {
        cnt += (b[i] - b[i - 1]) / mid;
        if ((b[i] - b[i - 1]) % mid == 0)
        {
            cnt--;
        }
        if (cnt > k)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cin >> len >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    int l = 0, r = len;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << l;
    return 0;
}