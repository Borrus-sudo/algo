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
    string s;
    cin >> s;
    int n = s.size();
    int l = 0, r = 0, none = 0;
    int i = 0;
    for (; i < n; i++) {
        if (s[i] == '<') {
            l++;
        } else {
            break;
        }
    }
    for (; i < n; i++) {
        if (s[i] == '*') {
            none++;
        } else {
            break;
        }
    }
    for (; i < n; i++) {
        if (s[i] == '>') {
            r++;
        } else {
            break;
        }
    }
    if (none + l + r == n && none < 2) {
        cout << (max(l, r) + none) << endl;
    } else {
        cout << -1 << endl;
    }
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