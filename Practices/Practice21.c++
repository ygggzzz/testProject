#include <iostream> //https://www.luogu.com.cn/problem/P1031 均分纸牌

using namespace std;

int a[110];

int main()
{
    int n, num = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        num += a[i];
    }
    num /= n;
    int tmp = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] != num)
        {
            a[i + 1] -= num - a[i];
            tmp++;
        }
    }
    cout << tmp << endl;
    return 0;
}