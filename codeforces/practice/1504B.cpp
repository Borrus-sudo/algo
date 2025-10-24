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
    string a, b;
    cin >> a >> b;
    int zeroes = 0, ones = 0;
    vector<int> possibs;
    possibs.push_back(0);
    for (int i = 0; i < n; i++) {
        char c = a[i];
        if (c == '0')
            zeroes++;
        else
            ones++;
        if (zeroes == ones) {
            possibs.push_back(i + 1);
        }
    }
    for (int i = n; i > possibs.back(); i--) {
        if (a[i - 1] != b[i - 1]) {
            cout << "NO" << endl;
            return;
        }
    }
    for (int i = possibs.size() - 1; i > 0; i--) {
        // create indices
        int leftEnd = possibs[i - 1] - 1;
        int rightEnd = possibs[i] - 1;
        // all elements are same or the bit flip of them is same, we are fine
        bool same = true, opp = true;
        for (int i = leftEnd + 1; i <= rightEnd; i++) {
            if (a[i] != b[i]) {
                same = false;
            }
            if ((a[i] - '0') != !(b[i] - '0')) {
                opp = false;
            }
        }
        if (!same && !opp) {
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

    int TC = 1;
    cin >> TC;

    while (TC--)
        solve();

    return 0;
}