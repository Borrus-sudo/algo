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
    int start = 1;
    int end = n;
    int left, right;
    unordered_map<int, pair<ll, ll>> og;
    // find me the first instance where it is broken
    while (start <= end) {
        int mid = start + (end - start) / 2;
        ll expected, received;
        int key = n + mid;
        if (og.count(key)) {
            auto pair = og[key];
            expected = pair.first;
            received = pair.second;
        } else {
            cout << "1" << " " << 1 << " " << mid << endl;
            cin >> expected;
            cout << "2" << " " << 1 << " " << mid << endl;
            cin >> received;
            og[key] = {expected, received};
        }
        if (expected == received) {
            start = mid + 1;
        } else {
            left = mid;
            end = mid - 1;
        }
    }
    start = 0;
    end = n;
    // find the me the first instance it is broke but from the end
    while (start <= end) {
        int mid = start + (end - start) / 2;
        ll expected, received;
        int key = mid * n + n;
        if (og.count(key)) {
            auto pair = og[key];
            expected = pair.first;
            received = pair.second;
        } else {
            cout << "1" << " " << mid << " " << n << endl;
            cin >> expected;
            cout << "2" << " " << mid << " " << n << endl;
            cin >> received;
            og[key] = {expected, received};
        }
        if (expected == received) {
            end = mid - 1;  // unreachable ig
        } else {
            right = mid;
            start = mid + 1;
        }
    }
    cout << "! " << left << " " << right << endl;
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