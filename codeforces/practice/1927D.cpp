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
    vector<int> nums(n);
    for (int& num : nums)
        cin >> num;
    int q;
    cin >> q;
    vector<pair<int, int>> qrs(q, pair<int, int>());
    for (auto& [a, b] : qrs)
        cin >> a >> b;
    // go backwards and are for all
    vector<int> cache(n);
    cache[n - 1] = -1;
    for (int j = n - 2; j >= 0; j--) {
        if (nums[j] != nums[j + 1]) {
            cache[j] = j + 1;
        } else {
            cache[j] = cache[j + 1];
        }
    }
    for (auto& [a, b] : qrs) {
        if (b - a + 1 == 1) {
            cout << -1 << " " << -1 << endl;
            continue;
        }
        int brother = cache[a - 1];
        if (brother == -1) {
            cout << -1 << " " << -1 << endl;
            continue;
        }
        if (brother + 1 > b) {
            cout << -1 << " " << -1 << endl;
            continue;
        }
        cout << a << " " << (brother + 1) << endl;
    }
    cout << endl;
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