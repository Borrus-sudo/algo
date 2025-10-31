#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool has2x2Square(const vector<string>& g, int n) {
    for (int i = 0; i + 1 < n; i++) {
        for (int j = 0; j + 1 < n; j++) {
            if (g[i][j] == '#' && g[i][j + 1] == '#' && g[i + 1][j] == '#' &&
                g[i + 1][j + 1] == '#')
                return true;
        }
    }
    return false;
}

bool checkDiagonals(const vector<string>& g, int n, bool principal) {
    vector<int> diagIDs;
    int id = 0;
    if (principal) {
        for (int col = 0; col < n; col++) {  // start from top row
            int i = 0, j = col, cnt = 0;
            while (i < n && j < n) {
                if (g[i][j] == '#')
                    cnt++;
                i++, j++;
            }
            if (cnt > 0)
                diagIDs.push_back(id);
            id++;
        }
        for (int row = 1; row < n; row++) {  // start from first column
            int i = row, j = 0, cnt = 0;
            while (i < n && j < n) {
                if (g[i][j] == '#')
                    cnt++;
                i++, j++;
            }
            if (cnt > 0)
                diagIDs.push_back(id);
            id++;
        }
    } else {
        for (int col = 0; col < n; col++) {  // start from top row
            int i = 0, j = col, cnt = 0;
            while (i < n && j >= 0) {
                if (g[i][j] == '#')
                    cnt++;
                i++, j--;
            }
            if (cnt > 0)
                diagIDs.push_back(id);
            id++;
        }
        for (int row = 1; row < n; row++) {  // start from last column
            int i = row, j = n - 1, cnt = 0;
            while (i < n && j >= 0) {
                if (g[i][j] == '#')
                    cnt++;
                i++, j--;
            }
            if (cnt > 0)
                diagIDs.push_back(id);
            id++;
        }
    }

    if (diagIDs.empty())
        return true;
    if (diagIDs.size() == 1)
        return true;
    if (diagIDs.size() == 2 && abs(diagIDs[0] - diagIDs[1]) == 1)
        return true;
    return false;
}

void solve() {
    int n;
    cin >> n;
    vector<string> g(n);
    for (auto& s : g)
        cin >> s;

    if (checkDiagonals(g, n, true)) {
        cout << "YES\n";
        return;
    }
    if (checkDiagonals(g, n, false)) {
        cout << "YES\n";
        return;
    }

    if (has2x2Square(g, n)) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}
