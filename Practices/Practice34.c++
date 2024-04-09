#include <bits/stdc++.h> //https://www.luogu.com.cn/problem/P1037?contestId=83991 产生数
using namespace std;

string str;
int k;
int dis[20][20]; // 记录点i到点j的连通关系，1为连通，0为不连通
bool vis[20];
int t[5000], num[20]; // num数组表示数字0~9的每个数字的可变换种类，t数组表示str中每个数字的变换种类
int ans;

// 高精度乘法
vector<int> mul(vector<int> &A, int b)
{
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || t; i++)
    {
        if (i < A.size())
            t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    return C;
}

int main()
{
    cin >> str >> k;
    for (int i = 0, a, b; i < k; i++)
    {
        cin >> a >> b;
        dis[a][b] = 1; // 将点a到点b设为连通
    }

    int len = str.size();
    // floyd!!!!，这里先用flody将每个点的连通关系找到
    for (int k = 1; k <= 9; k++)
    {
        for (int i = 0; i <= 9; i++)
        {
            for (int j = 0; j <= 9; j++)
            {
                // 如果点i到点k连通，并且点k到点j连通，那么点i到点j连通，所以dis[i][j]=1
                if (dis[i][k] && dis[k][j])
                    dis[i][j] = 1;
            }
        }
    }
    for (int i = 0; i <= 9; i++)
    {                  // 算出数字0~9每个数字的连通数有多少
        dis[i][i] = 1; // 它自己到自己也是一种连通
        for (int j = 0; j <= 9; j++)
        {
            if (dis[i][j])
                num[i]++; // 如果点i到点j连通，那么num[i]的种类+1
            // 这里的num[0]就是数字0的连通数，num[1]就是数字1的连通数
        }
    }

    for (int i = 0; i < len; i++)
    {                             // 算出str中每个数字的连通数
        t[i] = num[str[i] - '0']; // str[i]-'0'表示它是数字几，而num[str[i]-'0']表示该数值的数字的连通数
    }

    // 高精度计算
    vector<int> C;
    C.push_back(t[0]);
    //	while(t[0]){
    //		C.push_back(t[0]%10);
    //		t[0]/=10;
    //	}

    for (int i = 1; i < len; i++)
    {
        C = mul(C, t[i]);
    }
    for (int i = C.size() - 1; i >= 0; i--)
    {
        cout << C[i];
    }
    return 0;
}
