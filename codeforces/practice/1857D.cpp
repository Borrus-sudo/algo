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
    vector<int> a(n);
    vector<int> b(n);

    for (int& elem : a)
        cin >> elem;

    for (int& elem : b)
        cin >> elem;

    vector<pair<int, int>> res;
    for (int i = 0; i < n; i++) {
        res.push_back({a[i] - b[i], i + 1});
    }
    sort(all(res));
    int resVals = res.back().first;
    vector<int> svs;
    for (auto [val, idx] : res) {
        if (val == resVals)
            svs.push_back(idx);
    }
    cout << svs.size() << endl;
    for (int sv : svs)
        cout << sv << " ";
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