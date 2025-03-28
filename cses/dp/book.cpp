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
    int n, x;
    cin >> n >> x;
    vector<int> prices(n);
    vector<int> pages(n);
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

    for (int &price : prices)
        cin >> price;
    for (int &page : pages)
        cin >> page;

    for (int i = 1; i <= n; i++)
    {
        int curr_price = prices[i - 1];
        int curr_page = pages[i - 1];
        for (int j = 1; j <= x; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= curr_price)
                smax(dp[i][j], dp[i - 1][j - curr_price] + curr_page);
        }
    }

    cout << dp[n][x];
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