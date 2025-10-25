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

void query(bool bPres, int a, string s) {
    if (!bPres) {
        cout << a << endl;
        return;
    }
    bool cont = true;
    int ans = 0;
    while (cont) {
        for (char c : s) {
            if (c == 'B') {
                a /= 2;
                ans++;
            } else {
                a -= 1;
                ans++;
            }
            if (a == 0) {
                cont = false;
                cout << ans << endl;
                break;
            }
        }
    }
}

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> nums(q);
    for (int& num : nums)
        cin >> num;
    bool bPres = false;
    for (char c : s) {
        if (c == 'B') {
            bPres = true;
            break;
        }
    }
    for (int q : nums)
        query(bPres, q, s);
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