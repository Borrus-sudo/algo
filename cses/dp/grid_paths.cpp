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
    vector<vector<char>> grid(n, vector<char>(n, '\0'));
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            cin >> grid[row][col];
        }
    }

    if (grid[0][0] != '*')
        dp[0][0] = 1;

    for (int col = 0; col < n; col++)
    {
        for (int row = 0; row < n; row++)
        {
            if (grid[row][col] != '*')
            {
                if (row + 1 < n && grid[row + 1][col] != '*')
                {
                    dp[row + 1][col] += dp[row][col];
                    dp[row + 1][col] %= m;
                }
                if (col + 1 < n && grid[row][col + 1] != '*')
                {
                    dp[row][col + 1] += dp[row][col];
                    dp[row][col + 1] %= m;
                }
            }
        }
    }

    cout << dp[n - 1][n - 1];
}

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