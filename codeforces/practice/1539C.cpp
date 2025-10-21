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
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> nums(n);
    vector<ll> diffs;
    for (ll& num : nums)
        cin >> num;
    // now I have n elemetns
    sort(all(nums));
    ll ans = 1;
    // sorted all elements, but the qn is whether I should check for
    for (int i = 0; i < n - 1; i++) {
        if (nums[i + 1] - nums[i] <= x)
            continue;
        ll reqK = (nums[i + 1] - nums[i] + x - 1) / x - 1;  // ceil baby
        diffs.push_back(reqK);
        ans++;
    }
    sort(all(diffs));
    for (auto req : diffs) {
        if (req <= k) {
            ans--;
            k -= req;
        } else {
            break;
        }
    }
    cout << ans << endl;
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
}