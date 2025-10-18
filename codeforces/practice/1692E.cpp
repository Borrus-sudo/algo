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
    int n, s, ops = INT_MAX;
    cin >> n >> s;
    vector<int> nums(n);
    vector<int> prefix(n + 1);
    for (int& num : nums)
        cin >> num;
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + nums[i - 1];
    }

    for (int left = 1; left <= n; left++) {
        int end = n;
        int start = left;
        int ans = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int val = prefix[mid] - prefix[left - 1];
            if (val <= s) {
                if (val == s)
                    ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        if (ans == -1)
            continue;
        smin(ops, n - (ans - left + 1));
    }
    if (ops == INT_MAX)
        ops = -1;
    cout << ops << endl;
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