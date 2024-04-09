#include <iostream> //https://www.luogu.com.cn/problem/P1044?contestId=83991 栈
using namespace std;
#define ll long long
int f[20][20];
int dfs(int i, int j) // i是头部中里的数，j是栈中的数
{
    if (f[i][j])
        return f[i][j];
    if (i == 0)
        return f[i][j] = 1;
    if (j == 0)
        return f[i][j] = dfs(i - 1, j + 1);
    return f[i][j] = dfs(i - 1, j + 1) + dfs(i, j - 1);
}
int main()
{
    int n;
    cin >> n;
    cout << dfs(n, 0) << endl;
    return 0;
}