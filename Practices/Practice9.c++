#include <iostream> //https://www.luogu.com.cn/problem/P1803 线段覆盖
#include <algorithm>
using namespace std;
const int MAX = 1e6 + 5;
struct com
{
    long long a;
    long long b;
};

bool cmp(com a, com b)
{
    return a.b < b.b;
}

int main()
{
    int res = 1;
    long long n;
    cin >> n;
    com com[MAX];
    for (int i = 0; i < n; i++)
    {
        cin >> com[i].a >> com[i].b;
    }
    sort(com, com + n, cmp);
    long long last = com[0].b;
    for (int i = 1; i < n; i++)
    {
        if (com[i].a >= last)
        {
            res++;
            last = com[i].b;
        }
    }
    cout << res;
    return 0;
}