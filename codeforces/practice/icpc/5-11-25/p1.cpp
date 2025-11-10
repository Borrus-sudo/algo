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
    string s = to_string(n);
    if (s.size() == 1) {
        cout << n << endl;
        return;
    }
    reverse(all(s));
    int remove = -1;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] - '0' > s[i + 1] - '0') {
            // remove this
            remove = i;
            break;
        }
    }
    if (remove == -1) {
        remove = n - 1;
    }
    string res = "";
    for (int i = 0; i < n; i++) {
        if (remove == i) {
            continue;
        }
        res += s[i];
    }
    reverse(all(res));
    int ans = stoi(res);
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