#include <bits/stdc++.h>
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
    int n;
    cin >> n;
    int x;
    cin >> x;
    vector<int> a(n);
    vector<int> dp(x + 1, INT_MAX);
    dp[0] = 1;

    for (int& elem : a)
        cin >> elem;

    for (int i = 1; i <= x; i++) {
        for (int ai : a) {
            if (i - ai >= 0 && dp[i - ai] != INT_MAX)
                smin(dp[i], dp[i - ai] + 1);
        }
    }
    if (dp[x] == INT_MAX)
        dp[x] = 0;
    cout << (dp[x] - 1);
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