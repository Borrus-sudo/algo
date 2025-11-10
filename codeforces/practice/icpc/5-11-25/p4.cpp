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

string num2bin(int num) {
    string s(16, '0');
    for (int i = 15; i >= 0; --i) {
        s[i] = (num & 1) ? '1' : '0';
        num >>= 1;
    }
    return s;
}

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    vector<string> bins;
    ll res = 0;
    for (int& num : nums) {
        cin >> num;
        res |= num;
        bins.push_back(num2bin(num));
    }

    set<int> imp;
    vector<int> nimp;
    map<int, int> str;
    vector<int> indicesImp;

    for (int col = 0; col < 16; col++) {
        vector<int> found;
        for (int row = 0; row < n; row++) {
            if (bins[row][col] == '1') {
                found.push_back(row);
            }
        }
        if (found.size()) {
            sort(all(found), [&nums](auto a, auto b) { return nums[a] < nums[b]; });
            // double committed cases
            imp.insert(found.back());  // this is the problem, we need to make sure that this bit
                                       // has not been set
            str[found.back()] = col;   // also make sure that we don't dpen
            indicesImp.push_back(found.back());
        }
    }
    // found all imp indices
    for (int i = 0; i < n; i++) {
        if (!imp.count(i)) {
            nimp.push_back(i);
        }
    }
    ll ans = 0;
    string output = "";
    ans += (res);
    // sort(all(nimp), [&](auto a, auto b) { return nums[a] < nums[b]; });
    // remove non-imp
    // vector<int> ors(nimp.size(), 0);
    // for (int i = nimp.size() - 1; i >= 0; i--) {
    //     ors[i] |= nimp[i];
    //     if (i + 1 != nimp.size()) {
    //         ors[i] |= ors[i + 1];
    //     }
    // }
    // int idx = 0;
    for (int elem : nimp) {
        output += (to_string(elem + 1) + " ");
        ans += res;
        // ans += ors[idx++];
    }
    sort(all(indicesImp), [&](auto a, auto b) { return nums[a] < nums[b]; });
    for (int idx : indicesImp) {
        output += (to_string(idx + 1) + " ");
        int col = str[idx];
        res = res & (~(1 << col));
        ans += res;
    }
    cout << ans << endl;
    cout << output << endl;

    // sort them row wise
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