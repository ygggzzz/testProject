#include <iostream> //https://www.luogu.com.cn/problem/P1004?contestId=83991 方格取数
using namespace std;

int a[10][10];
int n;
int ans;

void input();
void dfs(int row, int col, int sum, int flag);

int main()
{
    input();
    dfs(1, 1, 0, 0);
    cout << ans;
    return 0;
}

void dfs(int row, int col, int sum, int flag)
{
    int num;
    if (row > n || col > n)
    {
        return;
    }
    if (row == n || col == n)
    {
        if (flag == 0)
        {
            dfs(1, 1, sum, 1);
        }
        else
        {
            ans = max(ans, sum + a[n][n]);
        }
    }
    num = a[row][col];
    a[row][col] = 0;
    dfs(row + 1, col, sum + num, flag);
    dfs(row, col + 1, sum + num, flag);
    a[row][col] = num;
}

void input()
{
    int x, y, z;
    cin >> n;
    while (1)
    {
        cin >> x >> y >> z;
        if (x == 0 && y == 0 && z == 0)
            break;
        a[x][y] = z;
    }
}