#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#define all(x) (x).begin, (x).end()
using namespace std;

template <typename S, typename T>
void smax(S& a, const T& b) {
    if (a < b)
        a = b;
};

template <typename S, typename T>
void smin(S& a, const T& b) {
    if (a > b)
        a = b;
};

using ll = long long;
const int m = 1e9 + 7;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int& coin : coins)
        cin >> coin;
    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    for (int coin : coins) {
        for (int i = coin; i <= x; i++) {
            dp[i] += dp[i - coin];
        }
    }

    cout << dp[x];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int TC = 1;
    // cin >> TC;

    while (TC--)
        solve();

    return 0;
}