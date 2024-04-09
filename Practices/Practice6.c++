#include <iostream> //https://www.luogu.com.cn/problem/P2240?contestId=114040 阿里巴巴拿金币
#include <algorithm>
using namespace std;

struct money
{
    int a;
    int b;
    double c;
};

bool cmp(money x, money y)
{
    return x.c > y.c;
}

int main()
{
    int n, t;
    cin >> n >> t;
    money money[10001];
    double res = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> money[i].a >> money[i].b;
        money[i].c = (1.0 * money[i].b / money[i].a);
    }
    sort(money, money + n, cmp);
    for (int i = 0; i < n; i++)
    {
        if (t > money[i].a)
        {
            res += money[i].b;
            t = t - money[i].a;
        }
        else
        {
            res += money[i].c * t;
            break;
        }
    }
    printf("%.2lf", res);
    return 0;
}