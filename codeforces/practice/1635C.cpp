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
    vector<int> nums(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> nums[i];
    if (!(nums[n - 1] <= nums[n])) {
        cout << -1 << endl;
        return;
    }
    if (nums[n - 1] < 0 && nums[n] < 0) {
        // the array better be sorted
        for (int i = 1; i < n; i++) {
            if (!(nums[i] <= nums[i + 1])) {
                cout << -1 << endl;
                return;
            }
        }
        cout << 0 << endl;
        return;
    }
    cout << n - 2 << endl;
    for (int i = n - 2; i >= 1; i--) {
        cout << i << " " << (n - 1) << " " << (n) << endl;
    }
    return;
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