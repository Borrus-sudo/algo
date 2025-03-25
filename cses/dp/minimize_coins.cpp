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

int combo(int sum, vector<int> &dp, vector<int> coins)
{
    if (sum < 0)
        return -1;
    if (sum == 0)
        return 0;
    if (dp[sum] != -2) {
        return dp[sum];
    }

    int used = -1;
    for (int coin : coins)
    {
        if (sum - coin >= 0)
        {
            int subUsed = combo(sum - coin, dp, coins) + 1;
            if (subUsed == 0)
                continue;
            if (used == -1)
                used = subUsed;
            else
                smin(used, subUsed);
        }
    }
    return dp[sum] = used;
}

void solve()
{
    int n;
    cin >> n;
    int x;
    cin >> x;
    vector<int> coins(n, 0);
    for (int &coin : coins)
        cin >> coin;
    vector<int> dp(x + 1, -2);
    cout << combo(x, dp, coins);
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