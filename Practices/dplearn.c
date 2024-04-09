#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int f[N]; // f数组存储的是最长不上升序列（注意不是子序列）
int g[N]; // g数组存储的是最长上升序列（注意不是子序列）
int h[N];
int n;

int main()
{
    while (cin >> h[++n])
        ;
    n--;

    int res = 1, cnt = 1;
    f[1] = g[1] = h[1];
    for (int i = 2; i <= n; i++)
    {
        if (h[i] <= f[res])
            f[++res] = h[i];
        else
        {
            int k = upper_bound(f + 1, f + res + 1, h[i], greater<int>()) - f;
            f[k] = h[i];
        }

        if (h[i] > g[cnt])
            g[++cnt] = h[i];
        else
        {
            int k = lower_bound(g + 1, g + cnt + 1, h[i]) - g;
            g[k] = h[i];
        }
    }

    printf("%d\n%d\n", res, cnt);

    return 0;
}

/* 题目描述
某国为了防御敌国的导弹袭击，发展出一种导弹拦截系统。但是这种导弹拦截系统有一个缺陷：虽然它的第一发炮弹能够到达任意的高度，但是以后每一发炮弹都不能高于前一发的高度。某天，雷达捕捉到敌国的导弹来袭。由于该系统还在试用阶段，所以只有一套系统，因此有可能不能拦截所有的导弹。

输入导弹依次飞来的高度，计算这套系统最多能拦截多少导弹，如果要拦截所有导弹最少要配备多少套这种导弹拦截系统。

输入格式
一行，若干个整数，中间由空格隔开。

输出格式
两行，每行一个整数，第一个数字表示这套系统最多能拦截多少导弹，第二个数字表示如果要拦截所有导弹最少要配备多少套这种导弹拦截系统。 */