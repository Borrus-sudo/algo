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
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int& num : nums)
        cin >> num;
    vector<int> freq(m);
    for (int num : nums) {
        int rmdr = num % m;
        freq[rmdr]++;
    }
    int ans = 0;
    for (int rmdr = 0; rmdr <= (m / 2); rmdr++) {
        if (rmdr == 0) {
            if (freq[rmdr])
                ans++;
            continue;
        }
        int dualRmdr = m - rmdr;
        int deficit = (max(freq[rmdr], freq[dualRmdr]) - (min(freq[rmdr], freq[dualRmdr])));
        if (!deficit && max(freq[rmdr], freq[dualRmdr]))
            ans++;
        ans += deficit;
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