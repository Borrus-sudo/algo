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
    int n, q;
    cin >> n >> q;
    vector<ll> steps(n);
    vector<ll> qns(q);
    vector<ll> prefixMax(n + 1, LONG_MIN);
    vector<ll> prefixSum(n + 1);

    for (auto &step : steps) cin >> step;
    for (auto &qn : qns) cin >> qn;

    for (int i = 1; i <= n; i++) {
        prefixMax[i] = max(prefixMax[i - 1], steps[i - 1]);
        prefixSum[i] = prefixSum[i - 1] + steps[i - 1];
    }

    // now binary search of sorts. Find the maxiumum most
    for (auto qn : qns) {
        int left = 1;
        int right = n;
        ll res = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            ll maxVal = prefixMax[mid];
            if (maxVal > qn) {
                // problem
                // I need to decrease right
                right = mid - 1;
            } else {
                // accepted solution
                res = prefixSum[mid];
                left = mid + 1;
            }
        }
        cout << res << " ";
    }
    cout << endl;
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