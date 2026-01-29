#include <bits/stdc++.h>
using namespace std;

int maxDiameter = INT_MIN;
vector<int> dist(2e5 + 1);
int dfs(int root, int parent, vector<vector<int>>& adjm) {
    int maxLen = 0;
    for (int child : adjm[root]) {
        if (child == parent)
            continue;
        maxDiameter = max(maxDiameter, maxLen + dfs(child, root, adjm) + 1);
        maxLen = max(maxLen, dist[child] + 1);
    }
    dist[root] = maxLen;
    return maxLen;
}

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    vector<vector<int>> adjm(n + 1);
    for (int i = 1; i <= n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adjm[a].push_back(b);
        adjm[b].push_back(a);
    }
    dfs(1, 1, adjm);
    cout << maxDiameter << endl;
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
};