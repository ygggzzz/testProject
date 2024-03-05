#include <iostream>
using namespace std;

int dp[1001];
int main()
{
    int i;
    int n;
    cin >> n;
    int nums[1001];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    dp[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        if (i == 1)
        {
            dp[1] = max(nums[0], nums[1]);
        }
        else
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
    }
    cout << dp[n - 1] << endl;
}
