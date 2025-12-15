#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e6 + 7;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (auto& v : arr)
        cin >> v;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    dp[0][0] = 1;
    for (int j = 1; j <= m; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= n; i++) {
        vector<int> pref(m + 1, 0);

        pref[0] = dp[i - 1][0];
        for (int j = 1; j <= m; j++) {
            pref[j] = (pref[j - 1] + dp[i - 1][j]) % MOD;
        }

        int limit = arr[i - 1];

        for (int j = 0; j <= m; j++) {
            int left = j - limit - 1 >= 0 ? pref[j - limit - 1] : 0;
            dp[i][j] = (pref[j] - left + MOD) % MOD;
        }
    }

    cout << dp[n][m] << endl;
    return 0;
}