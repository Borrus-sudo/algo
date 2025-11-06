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
    multiset<int> swords;
    vector<int> monsters(m);
    vector<int> newS(m);

    for (int i = 1; i <= n; i++) {
        int sword;
        cin >> sword;
        swords.insert(sword);
    }
    for (int& ms : monsters)
        cin >> ms;
    for (int& ns : newS)
        cin >> ns;
    vector<pair<int, int>> nonzero;
    vector<pair<int, int>> zero;
    for (int i = 0; i < m; i++) {
        if (newS[i] == 0)
            zero.push_back({newS[i], monsters[i]});
        else
            nonzero.push_back({newS[i], monsters[i]});
    }
    sort(all(nonzero), [](auto a, auto b) { return a.second < b.second; });
    sort(all(zero), [](auto a, auto b) { return a.second < b.second; });

    int ans = 0;
    for (auto [newS, monster] : nonzero) {
        auto pos = swords.lower_bound(monster);
        if (pos == swords.end())
            continue;
        ans++;
        int sword = *pos;
        swords.erase(pos);
        int newSword = max(newS, sword);
        swords.insert(newSword);
    }
    for (auto [newS, monster] : zero) {
        auto pos = swords.lower_bound(monster);
        if (pos == swords.end())
            continue;
        ans++;
        swords.erase(pos);
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