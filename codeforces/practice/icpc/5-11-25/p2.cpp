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
    unordered_map<string, vector<int>> cache;
    int n;
    cin >> n;
    while (n--) {
        string s;
        int type;
        cin >> s;
        cin >> type;
        if (cache.count(s)) {
            cache[s][type]++;
        } else {
            cache[s] = vector<int>(2);
            cache[s][type]++;
        }
    }
    int ans = 0;
    for (auto [_, freq] : cache) {
        ans += max(freq[0], freq[1]);
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