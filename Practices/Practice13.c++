#include <iostream> //https://www.luogu.com.cn/problem/P2142 高精度减法
#include <string>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int a1[100001] = {0};
    int a2[100001] = {0};
    int a3[100001] = {0};
    char flag = '+';
    if (s1.size() < s2.size() || s1.size() == s2.size() && s1 < s2)
    {
        swap(s1, s2);
        flag = '-';
    }
    for (int i = 0; i < s1.size(); i++)
    {
        a1[i] = s1[s1.size() - i - 1] - '0';
    }
    for (int i = 0; i < s2.size(); i++)
    {
        a2[i] = s2[s2.size() - i - 1] - '0';
    }
    for (int i = 0; i < s1.size(); i++)
    {
        if (a1[i] < a2[i])
        {
            a1[i] = a1[i] + 10;
            a1[i + 1]--;
        }
        a3[i] = a1[i] - a2[i];
    }
    if (flag == '-')
    {
        cout << flag;
    }
    int index = 0;
    for (int i = s1.size() - 1; i >= 0; i--)
    {
        if (a3[i] != 0)
        {
            index = i;
            break;
        }
    }
    for (int i = index; i >= 0; i--)
    {
        cout << a3[i];
    }
    return 0;
}