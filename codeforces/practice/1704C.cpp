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
    ll n, m;
    cin >> n >> m;
    vector<ll> infected(m);
    for (auto &elem : infected) cin >> elem;
    if (m == 1) {
        cout << 2 << endl;
        return;
    }
    sort(all(infected));
    // we need to pair the first with the second, second with the third and keep going on
    vector<pair<ll, ll>> dist;

    for (int i = 0; i < m - 1; i++) {
        dist.push_back({infected[i], infected[i + 1]});
    };
    ll jumps = (infected[0] - infected[m - 1] + n) % n;
    dist.push_back({infected[0],
                    infected[0] + jumps});  // this is equivalent to infected[m - 1] and infected[0]

    auto cmp = [](pair<ll, ll> &a, pair<ll, ll> &b) {
        int dist1 = a.second - a.first;
        int dist2 = b.second - b.first;
        // if I return true, b will have more priority
        // we need to give more priority to the larger length
        return dist2 > dist1;
    };
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, decltype(cmp)> longest(all(dist), cmp);
    int days = 0;
    ll ans = m;
    while (!longest.empty()) {
        auto [a, b] = longest.top();
        longest.pop();
        int aF = a + days;
        int bF = b - days;
        int houses = b - a - 1;
        int uninfected = bF - aF - 1;

        if (aF >= bF) {
            ans += houses;
            continue;
        }
        if (uninfected == 0) {
            ans += houses;
        } else if (uninfected == 1 || uninfected == 2) {
            days++;
            ans += (houses - 1);
        } else {
            ans += 2 * days + 1;
            days += 2;
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