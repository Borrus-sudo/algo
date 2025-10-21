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

int largestFactor(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return (n / i);
        }
    }
    return 1;
}

void solve() {
    int n;
    cin >> n;
    char c;
    cin >> c;
    string s;
    cin >> s;
    string check = string(n, c);
    if (s == check) {
        cout << 0 << endl;
        return;
    }
    for (int i = 2; i <= n; i++) {
        bool canDo = true;
        for (int j = i; j <= n; j += i) {
            if (s[j - 1] != c) {
                canDo = false;
                break;
            }
        }
        if (canDo) {
            cout << 1 << endl;
            cout << i << endl;
            return;
        }
    }
    cout << 2 << endl;
    cout << n << " " << (n - 1) << endl;
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