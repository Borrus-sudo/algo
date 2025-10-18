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

int bin_search(vector<ll>& prefix, int bottleIdx, int x) {
    int day = 1;
    int start = 0;
    int end = 1e9 - 1;
    int ans = 0;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        // cost of the bottle at this day where the day is (mid + 1)
        // so (bottleIdx + 1)*(mid)
        ll cost = prefix[bottleIdx] + ((ll)mid) * (bottleIdx + 1);
        if (cost <= x) {
            ans = (mid + 1);
            if (cost == x)
                return ans;
            start = mid + 1;
        } else
            end = mid - 1;
    }
    return ans;
}

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> nums(n);
    for (int& n : nums)
        cin >> n;
    sort(all(nums));
    vector<ll> prefix(n);
    prefix[0] = nums[0];
    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + nums[i];
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += bin_search(prefix, i, x);
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