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

ll cnt(string s, set<string>& cache) {
    int n = s.size();
    ll res = 0;
    string a = {s[0]};
    string b = {s[1]};
    if (n < 2) {
        return 1;
    }
    if (n == 2) {
        if (!cache.count(a)) {
            cache.insert(a);
            res++;
        }
        if (!cache.count(b)) {
            cache.insert(b);
            res++;
        }
        return res;
    }
    // find the part one and part 2
    string cmn = s.substr(2);
    string left = a + cmn;
    string right = b + cmn;
    res += cnt(left, cache);
    if (a != b)
        res += cnt(right, cache);
    res++;  // for no operation scenarios

    return res;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    set<string> cache;
    cout << cnt(s, cache) << endl;
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