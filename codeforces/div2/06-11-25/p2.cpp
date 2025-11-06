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
    int even = 0;
    int first, second;
    for (int& num : nums) {
        cin >> num;
        if (num % 2 == 0) {
            even++;
            if (even == 1) {
                first = num;
            } else if (even == 2) {
                second = num;
            }
        }
    }
    if (even >= 2) {
        cout << min(first, second) << " " << max(first, second) << endl;
        return;
    }
    sort(all(nums));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < min(n, 100); j++) {
            int rem = nums[j] % nums[i];
            if (rem % 2 == 0) {
                cout << nums[i] << " " << nums[j] << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
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