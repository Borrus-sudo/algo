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
    string s;
    cin >> s;
    int left = 0;
    int right = n - 1;
    set<char> opts;
    char must = ' ';
    int ans = INT_MAX;
    for (int i = 'a'; i <= 'z'; i++) {
        char letter = i;
        int left = 0;
        int right = n - 1;
        int curr = 0;
        while (left <= right) {
            if (s[left] == s[right]) {
                left++;
                right--;
                continue;
            }
            if (s[left] == letter) {
                left++;
                curr++;
                continue;
            }
            if (s[right] == letter) {
                right--;
                curr++;
                continue;
            }
            curr = INT_MAX;
            break;
        }
        smin(ans, curr);
    }
    if (ans == INT_MAX)
        cout << -1 << endl;
    else
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