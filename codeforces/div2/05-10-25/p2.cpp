#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define all(x) (x).begin(), (x).end()
#define dbg(x) cout << "Line(" << __LINE__ << ") -> " << #x << " = " << (x) << endl;

using namespace std;

template <typename S, typename T>
void smax(S &a, const T &b) {
    if (a < b) a = b;
};

template <typename S, typename T>
void smin(S &a, const T &b) {
    if (a > b) a = b;
};

using ll = long long;
const int INF = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<string> maze(n, string(n, ' '));
    vector<vector<bool>> escape(n, vector<bool>(n, false));
    int req = k;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (req == 0) {
                if (row > 0 && !escape[row - 1][col]) {
                    maze[row][col] = 'U';
                } else if (row < n - 1 && !escape[row + 1][col]) {
                    maze[row][col] = 'D';
                } else if (col > 0 && !escape[row][col - 1]) {
                    maze[row][col] = 'L';
                } else if (col < n - 1 && !escape[row][col + 1]) {
                    maze[row][col] = 'R';
                } else {
                    cout << "NO" << endl;
                    return;
                }
            } else {
                // req exists
                if (row == 0 || escape[row - 1][col]) {
                    maze[row][col] = 'U';

                } else if (row == n - 1 || escape[row + 1][col]) {
                    maze[row][col] = 'D';

                } else if (col == 0 || escape[row][col - 1]) {
                    maze[row][col] = 'L';

                } else if (col == n - 1 || escape[row][col + 1]) {
                    maze[row][col] = 'R';

                } else {
                    // unreachable I think?
                    cout << "NO" << endl;
                    return;
                }
                req--;
                escape[row][col] = true;
            }
        }
    }
    cout << "YES" << endl;
    for (auto row : maze) {
        cout << row << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int TC = 1;
    cin >> TC;

    while (TC--) solve();

    return 0;
}