#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <string>
#include <algorithm>
#include <climits>
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

vector<int> digits(int a)
{
    vector<int> digitCollection;
    while (a != 0)
    {
        digitCollection.push_back(a % 10);
        a /= 10;
    }
    return digitCollection;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        vector<int> possiblities = digits(i);
        for (int digit : possiblities)
        {
            if (i - digit >= 0 && dp[i - digit] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i - digit] + 1);
            }
        }
    }
    cout << dp[n];
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