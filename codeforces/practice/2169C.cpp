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
    vector<int> a(n);
    for (int& num : a)
        cin >> num;
    vector<ll> prefix(n + 1);
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + a[i - 1];
    }
    ll maxLeft = LLONG_MIN;
    ll maxRight = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        int idx = i + 1;
        smax(maxRight, (ll)idx * idx + idx - (prefix[i + 1] - prefix[0]));
        
        smax(maxLeft, -1ll * idx * idx + idx + (prefix[i + 1] - prefix[0]));
    }
    ll res = prefix[n] + max(maxLeft + maxRight, 0ll);
    cout << res << endl;
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