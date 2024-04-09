#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

struct stu
{
    char name;
    int num;
};

bool cmp(stu s1, stu s2)
{
    return s1.num > s2.num;
}

int main()
{
    stu stu[101];
    int len = 0;
    char s;

    while (true)
    {
        cin >> s;
        if (s == 'E')
        {
            string endCheck;
            cin >> endCheck;
            if (endCheck == "ND")
                break;
            else
            {
                stu[len].name = 'E';           // 如果输入的是 'E'，将学生名字设置为 'E'
                stu[len].num = stoi(endCheck); // 将后续字符解析为学生编号
                len++;
            }
        }
        else
        {
            stu[len].name = s;
            cin >> stu[len].num;
            len++;
        }
    }

    sort(stu, stu + len, cmp);
    for (int i = 0; i < len; i++)
    {
        cout << stu[i].name << " " << stu[i].num << endl;
    }

    return 0;
}
