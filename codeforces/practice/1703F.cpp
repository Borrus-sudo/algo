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
    vector<int> nums(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> nums[i];

    vector<pair<int, int>> valid;
    for (int i = 1; i <= n; i++) {
        if (nums[i] < i) {
            valid.push_back({nums[i], i});
        }
    }
    // simple prefix sums
    vector<ll> prefix(n, 0);
    for (auto [val, idx] : valid) {
        prefix[val] += 1;
    }
    for (int i = 0; i < n; i++) {
        prefix[i] += (i == 0 ? 0 : prefix[i - 1]);
    }
    // now for every pair
    // we will see how many pairs are there before
    ll ans = 0;
    for (auto [val, idx] : valid) {
        if (idx != n)
            ans += (prefix[n - 1] - prefix[idx]);
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