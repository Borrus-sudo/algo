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
const int m = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
        dp[i][1] = 1;
        dp[i][2] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 2; j++)
        {
            for (int k = 1; k <= i; k++)
            {
                for (int l = 1; l <= j; l++)
                {
                    dp[i][j] += dp[i - k][j - l];
                    dp[i][j] %= m;
                }
            }
        }
    }

    cout << dp[n][2] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int TC = 1;
    cin >> TC;

    while (TC--)
        solve();

    return 0;
}