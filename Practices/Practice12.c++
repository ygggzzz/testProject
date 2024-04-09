#include <iostream> //https://www.luogu.com.cn/problem/P1601 A+B Problem（高精）
#include <string>
using namespace std;

using namespace std;

int main()
{
    string A;
    string B;
    int a[500] = {};
    int b[500] = {};
    int c[600] = {};

    cin >> A >> B;

    for (int i = 0; i < A.size(); i++)
    {
        // 置逆字符串A
        a[i] = A[A.size() - 1 - i] - '0';
    }
    for (int i = 0; i < B.size(); i++)
    {
        // 置逆字符串B
        b[i] = B[B.size() - 1 - i] - '0';
    }

    int temp = 0; // 存储进位
    for (int i = 0; i < 500; i++)
    { // 模拟手动计算进位
        temp = a[i] + b[i] + temp;
        c[i] = temp % 10;
        temp /= 10;
    }

    bool flag = 0;
    for (int i = 599; i >= 0; i--)
    { // 逆序输出，由于数组已经置逆，从第一个不为0的数字开始输出
        if (c[i] != 0)
            flag = 1;
        if (flag == 1)
            cout << c[i];
    }
    if (flag == 0)
    {
        // 考虑0 + 0 = 0的情况
        cout << c[0];
    }

    return 0;
}