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
    int n;
    cin >> n;
    string s;
    cin >> s;

    ll ans = 0;
    vector<int> elems;
    vector<bool> need(n + 1);
    vector<bool> curr(n + 1, true);

    for (int i = 0; i < n; i++) {
        need[i + 1] = s[i] - '0';
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            if (need[j]) break;
            if (!curr[j]) continue;
            ans += i;
            curr[j] = false;
        }
    }
    cout << ans << endl;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int TC = 1;
    cin >> TC;

    while (TC--) solve();

    return 0;
}