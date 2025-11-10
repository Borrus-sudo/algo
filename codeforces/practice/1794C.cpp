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
    for (int& num : nums) {
        cin >> num;
    }
    for (int i = 0; i < n; i++) {
        int start = 0;
        int end = i;
        int ans = -1;
        // binary search to find the place where
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int pos = i - mid + 1;
            if (pos <= nums[mid]) {
                ans = mid;
                end = mid - 1;
            } else if (pos > nums[mid]) {
                // rollback
                start = mid + 1;
            }
        }
        // ans is guaranteed to have an answer
        cout << (i - ans + 1) << " ";
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