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
const int N = 1e6 + 1;
int spf[N + 1];

void createSieve() {
    for (int i = 1; i <= N; i++)
        spf[i] = i;

    for (int i = 2; i * i <= N; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= N; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    // Do a spf on each of them and get the answer?
    int num;
    bool canDo = true;
    map<int, int> divs;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        while (num != 1) {
            int factor = spf[num];
            num /= spf[num];
            divs[factor]++;
        }
    }
    for (auto [_, freq] : divs) {
        if (freq % n != 0) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    createSieve();

    int TC = 1;
    cin >> TC;

    while (TC--)
        solve();

    return 0;
}