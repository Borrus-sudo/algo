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
    vector<int> gangs(n + 1, INT_MAX);
    vector<int> record(n + 1);
    for (int i = 0; i < n; i++) {
        int g;
        cin >> g;
        gangs[i] = g;
        record[i + 1] = g;
    }
    sort(all(gangs));
    int types = 0;
    for (int i = 0; i < n; i++) {
        if (gangs[i] != gangs[i + 1]) {
            types++;
        }
    }
    if (types < 2) {
        cout << "NO" << endl;
        return;
    }
    int key = find(all(record), gangs[n - 1]) - record.begin();
    int sub = find(all(record), gangs[0]) - record.begin();

    cout << "YES" << endl;
    for (int i = 1; i <= n; i++) {
        if (record[i] == record[key]) {
            if (i != key)
                cout << i << " " << sub << endl;
        } else {
            cout << i << " " << key << endl;
        }
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