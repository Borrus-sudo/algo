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
    map<int, int> cache;
    vector<vector<int>> nums(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        nums[i] = vector<int>(k);
        for (int& num : nums[i]) {
            cin >> num;
            cache[num]++;
        }
    }
    int maxSplit = n;
    for (auto bits : nums) {
        for (int bit : bits) {
            // figure out if this i
            if (cache[bit] == 1) {
                maxSplit--;
                break;
            }
        }
    }
    if (maxSplit == 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
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