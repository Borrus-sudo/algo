#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <string>
#include <algorithm>
#define all(x) (x).begin, (x).end()
using namespace std;

template <typename S, typename T>
void smax(S &a, const T &b)
{
    if (a < b)
        a = b;
};

template <typename S, typename T>
void smin(S &a, const T &b)
{
    if (a > b)
        a = b;
};

using ll = long long;
const int mod = 1e9 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    vector<vector<int>> dp(n, vector<int>(m + 1, 0));
    for (int &num : nums)
        cin >> num;
    if (nums[0] == 0)
        for (int i = 1; i <= m; i++)
            dp[0][i] = 1;
    else
        dp[0][nums[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        if (nums[i - 1] == 0)
        {
            if (nums[i] == 0)
            {
                for (int j = 1; j <= m; j++)
                {
                    dp[i][j] += dp[i - 1][j];
                    dp[i][j] %= mod;

                    if (j - 1 >= 1)
                    {
                        dp[i][j] += (dp[i - 1][j - 1]);
                        dp[i][j] %= mod;
                    }
                    if (j + 1 <= m)
                    {
                        dp[i][j] += (dp[i - 1][j + 1]);
                        dp[i][j] %= mod;
                    }
                }
            }
            else
            {
                dp[i][nums[i]] += (dp[i - 1][nums[i]]);
                dp[i][nums[i]] %= mod;
                if (nums[i] + 1 <= m)
                {
                    dp[i][nums[i]] += dp[i - 1][nums[i] + 1];
                    dp[i][nums[i]] %= mod;
                }
                if (nums[i] - 1 >= 1)
                {
                    dp[i][nums[i]] += dp[i - 1][nums[i] - 1];
                    dp[i][nums[i]] %= mod;
                }
            }
        }
        else
        {
            if (nums[i] == 0)
            {
                dp[i][nums[i - 1]] += (dp[i - 1][nums[i - 1]]);
                dp[i][nums[i - 1]] %= mod;
                if (nums[i - 1] + 1 <= m)
                {
                    dp[i][nums[i - 1] + 1] += (dp[i - 1][nums[i - 1]]);
                    dp[i][nums[i - 1] + 1] %= mod;
                }
                if (nums[i - 1] - 1 >= 1)
                {
                    dp[i][nums[i - 1] - 1] += (dp[i - 1][nums[i - 1]]);
                    dp[i][nums[i - 1] - 1] %= mod;
                }
            }
            else
            {
                if (abs(nums[i] - nums[i - 1]) <= 1)
                    dp[i][nums[i]] += (dp[i - 1][nums[i - 1]]);
                else
                {
                    cout << 0;
                    return;
                }
                dp[i][nums[i]] %= mod;
            }
        }
    }
    int ans = 0;
    for (int k = 1; k <= m; k++)
    {
        ans += dp[n - 1][k];
        ans %= mod;
    }
    cout << ans;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int TC = 1;
    // cin >> TC;

    while (TC--)
        solve();

    return 0;
}