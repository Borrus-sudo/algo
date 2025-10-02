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
    int n;
    cin >> n;
    vector<int> debit(n);
    vector<int> credit(n);
    vector<int> final(n);
    for (int &d : debit) cin >> d;
    for (int &c : credit) cin >> c;
    for (int i = 0; i < n; i++) {
        final[i] = credit[i] - debit[i];
    }
    sort(all(final));
    int left = 0;
    int right = n - 1;
    int ans = 0;
    while (left < right) {
        if (final[right] + final[left] >= 0) {
            ans++;
            right--;
            left++;
        } else {
            left++;
        }
    }
    cout << ans << endl;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int TC = 1;
    cin >> TC;

    while (TC--) solve();

    return 0;
}