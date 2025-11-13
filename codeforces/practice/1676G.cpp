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
const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> parents(n + 1, 1);
    vector<pair<int, int>> numbers(n + 1, pair<int, int>(0, 0));
    // idx 1 is just the root

    for (int i = 2; i <= n; i++) {
        cin >> parents[i];
    }

    string s;
    cin >> s;
    s = ' ' + s;  // sentinel value

    for (int i = 1; i <= n; i++) {
        char color = s[i];   // the color of the ith node
        if (color == 'W') {  // report the number to the parent
            numbers[i].first++;
        } else {
            numbers[i].second++;
        }
    }
    for (int i = n; i >= 2; i--) {
        int parent = parents[i];
        numbers[parent].first += numbers[i].first;
        numbers[parent].second += numbers[i].second;
    }
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        if (numbers[i].first == numbers[i].second) {
            ans++;
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

    while (TC--)
        solve();

    return 0;
}