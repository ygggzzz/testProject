#include <iostream> //https://www.luogu.com.cn/problem/P1056 排座椅
#include <algorithm>
#include <cstring>
using namespace std;
int m, n, k, le, d;
int x, y, p, q, h[2020], s[2020];
int main()
{
    int num1 = 0, num2 = 0;
    cin >> m >> n >> k >> le >> d;
    for (int i = 1; i <= d; i++)
    {
        scanf("%d %d %d %d", &x, &y, &p, &q); // 读入的四个坐标只用一次就没用了，所以不用开数组全存起来
        if (y == q)
            h[min(x, p)]++;
        else
            s[min(y, q)]++; // 其实a,b也用不到，也不用排序，这里就直接把h和s数组搞定
    }
    for (int i = 1; i <= k; i++)
    {
        int *ma = max_element(h + 1, h + m + 1); // 找到最大的地址
        *ma = -1;                                // 通过指针取值就可以直接修改，因为它返回的本就是需要修改的元素的地址，不需要一个一个找
    }
    for (int i = 1; i <= m; i++)
        if (h[i] == -1)
            printf("%d ", i);

    printf("\n");
    for (int i = 1; i <= le; i++)
    {
        int *ma = max_element(s + 1, s + n + 1);
        *ma = -1;
    }
    for (int i = 1; i <= n; i++)
        if (s[i] == -1)
            printf("%d ", i);
    return 0;
}