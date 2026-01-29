#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adjm(n + 1);
    vector<int> parentOf(n + 1);
    for (int i = 2; i <= n; i++) {
        int parent;
        cin >> parent;
        adjm[parent].push_back(i);
        parentOf[i] = parent;
    }

    // do an iterative dfs
    vector<int> subordinates(n + 1, 0);
    vector<bool> hasSeen(n + 1, false);

    stack<int> S;
    S.push(1);
    while (!S.empty()) {
        int top = S.top();
        if (hasSeen[top]) {
            S.pop();
            subordinates[parentOf[top]] += (subordinates[top] + 1);
            continue;
        }
        for (int child : adjm[top]) {
            S.push(child);  // when I see them
        }
        hasSeen[top] = true;
    }
    for (int i = 1; i <= n; i++)
        cout << subordinates[i] << " ";
    cout << endl;
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