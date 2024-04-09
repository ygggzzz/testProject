#include <iostream> //https://www.luogu.com.cn/problem/P5739?contestId=83991 计算阶乘
using namespace std;

long long ans = 1;

void dfs(int t);

int main()
{
    int n;
    cin >> n;
    dfs(n);
}

void dfs(int t)
{
    if(t==1)
    {
        cout << ans;
        return;
    }
    else
    {
        ans *= t;
        dfs(t-1);
    }
}