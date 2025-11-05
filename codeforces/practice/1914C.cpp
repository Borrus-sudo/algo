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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> b(n);
    for (int& elem : a)
        cin >> elem;
    for (int& elem : b)
        cin >> elem;
    priority_queue<int> maxHeap;
    int acc = 0;
    int ans = -1;
    // great use for debug ig?
    for (int i = 0; i < min(n, k); i++) {
        acc += a[i];
        maxHeap.push(b[i]);
        int local = acc + maxHeap.top() * (k - (i + 1));
        smax(ans, local);
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