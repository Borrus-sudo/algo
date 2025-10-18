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
#define input(nums)        \
    for (auto& num : nums) \
        cin >> num;

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

struct IdxStore {
    set<int> valid;
    bool isValid(int idx) {
        return !!valid.count(idx);
    }
    void init(int n) {
        for (int i = 0; i < n; i++) {
            valid.insert(i);
        }
    }
    void validate(int idx) {
        valid.insert(idx);
    }
    void invalidateAll() {
        valid.clear();
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> nums(n);
    input(nums);
    ll ans = accumulate(all(nums), 0ll);
    vector<vector<int>> queries(q, {0, 0, 0});
    for (auto& query : queries) {
        cin >> query[0];
        cin >> query[1];
        if (query[0] == 1)
            cin >> query[2];
    }
    int ce = -1;
    IdxStore store;
    store.init(n);
    for (auto query : queries) {
        if (query[0] == 1) {
            int idx = query[1] - 1;
            int& payload = nums[idx];
            if (!store.isValid(idx)) {
                payload = ce;
                store.validate(idx);
            }
            ans -= payload;
            nums[idx] = query[2];
            ans += payload;
            cout << ans << endl;
        } else {
            ce = query[1];
            ans = (ll)n * ce;
            store.invalidateAll();
            cout << ans << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int TC = 1;
    // cin >> TC;

    while (TC--)
        solve();

    return 0;
}