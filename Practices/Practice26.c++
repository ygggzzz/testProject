#include <iostream> //https://www.luogu.com.cn/problem/P1720?contestId=83991 月落乌啼算钱
#include <cmath>
using namespace std;

int main()
{
    double a, b;
    double c, d;
    int n;
    double res;
    cin >> n;
    a = (1 + sqrt(5)) / 2.0;
    b = (1 - sqrt(5)) / 2.0;
    c = pow(a, n);
    d = pow(b, n);
    res = (c - d) / sqrt(5);
    printf("%.2lf", res);
    return 0;
}
