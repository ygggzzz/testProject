#include <iostream> //https://www.luogu.com.cn/record/150824278 八皇后
using namespace std;

int n;
int res = 0;
int flag = 0;
int a[20];

void dfs(int t);
void output();
bool canplace(int row, int col);

int main()
{
    cin >> n;
    dfs(0);
    cout << res;
    return 0;
}

void dfs(int t)
{
    if (t == n)
    {
        res++;
        if (res <= 3)
        {
            output();
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (canplace(t, i))
            {
                a[t] = i;
                dfs(t + 1);
            }
        }
    }
}

bool canplace(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (a[i] == col || row - i == abs(col - a[i]))
        {
            return false;
        }
    }
    return true;
}

void output()
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] + 1 << " ";
    }
    cout << endl;
}