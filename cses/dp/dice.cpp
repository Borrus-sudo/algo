#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(i, 6); j++) {
            dp[i] += dp[i - j];
            dp[i] %= INF;
        }
    }
    cout << dp[n] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int TC = 1;
    while (TC--)
        solve();

    return 0;
}
