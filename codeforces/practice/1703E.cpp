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

int minChanges(vector<string> &matrix, pair<int, int> coords, pair<int, int> split) {
    auto [row, col] = coords;
    auto [right, down] = split;
    int freq[2] = {0, 0};
    freq[matrix[row][col] - '0']++;
    col += right;
    row += down;
    freq[matrix[row][col] - '0']++;
    col -= down;
    row += right;
    freq[matrix[row][col] - '0']++;
    col -= right;
    row -= down;
    freq[matrix[row][col] - '0']++;

    return min(freq[0], freq[1]);
}

void solve() {
    int n;
    cin >> n;
    vector<string> matrix(n, "");
    for (auto &row : matrix) cin >> row;
    int ans = 0;
    for (int i = 1; i <= n / 2; i++) {
        int pos = i - 1;
        int squareLen = n - 2 * pos;
        int jumps = squareLen - 1;

        pair<int, int> start = {pos, pos};
        pair<int, int> split = {jumps, 0};

        for (int i = 1; i < squareLen; i++) {
            ans += minChanges(matrix, start, split);
            start.second += 1;
            split.first--;
            split.second++;
        }
    }
    cout << ans << endl;
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