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

int book(int i, int x, int collected, vector<int> &pages, vector<int> &prices, vector<vector<int>> &dp)

{
    if (dp[i][x] != -1)
        return dp[i][x];
    if (i == pages.size())
        return collected;
    int taken = 0;
    if (x - prices[i] >= 0)
        taken = book(i + 1, x - prices[i], collected + pages[i], pages, prices, dp);
    int notTaken = book(i + 1, x, collected, pages, prices, dp);
    return dp[i][x] = max(taken, notTaken);
}

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> prices(n);
    vector<int> pages(n);

    for (int &price : prices)
        cin >> price;
    for (int &page : pages)
        cin >> page;

    cout << book(0, x, 0, pages, prices, vector<vector<int>>(n, vector<int>(x, -1)));
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