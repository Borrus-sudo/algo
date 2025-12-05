#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int lcs(string a, string b) {
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    // construct it back ig
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[i - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    int i = n, j = m;
    string ans = "";
    while (i >= 1 && j >= 1) {
        if (a[i - 1] == b[j - 1]) {
            ans += a[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
    return dp[n][m];
}

int knapsack(vector<int> weights, vector<int> profits, int max_cap) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(max_cap + 1));
    for (int i = 1; i <= n; i++) {
        int weight = weights[i - 1];
        int profit = profits[i - 1];

        for (int j = 1; j <= max_cap; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - weight >= 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - weight] + profit);
            }
        }
    }

    // Dicey, recheck
    int i = n, j = max_cap;
    vector<int> collectedItemWeights;
    while (i >= 1 && j >= 1) {
        if (dp[i][j] != dp[i - 1][j]) {
            // realize you have been picked up by some item
            // picked up the ith element and by that we mean i - 1
            int pickedupWeight = weights[i - 1];
            collectedItemWeights.push_back(i);
            j -= pickedupWeight;
        }
        i--;
    }
    reverse(collectedItemWeights.begin(), collectedItemWeights.end());
}

int mat_mul_min(vector<int> p) {
    int n = p.size() - 1;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    vector<vector<int>> split(n + 1, vector<int>(n + 1));

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    split[i][j] = k;
                }
            }
        }
    }

    return dp[1][n];
}

int main() {
    return 0;
}