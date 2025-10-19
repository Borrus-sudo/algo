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
    int biggest = nums[1];
    ll ans = 0;
    for (int i = 2; i <= n; i++) {
        smax(biggest, nums[i]);
        if (i % 2 == 0)
            nums[i] = biggest;
    }
    for (int i = 2; i <= n; i += 2) {
        bool left = nums[i] > nums[i - 1];
        bool right = i >= n || (nums[i] > nums[i + 1]);
        if (!left) {
            ans += (nums[i - 1] - nums[i] + 1);
            nums[i - 1] = nums[i] - 1;
        }
        if (!right) {
            ans += (nums[i + 1] - nums[i] + 1);
            nums[i + 1] = nums[i] - 1;
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