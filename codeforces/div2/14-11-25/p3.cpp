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
    vector<int> nums(n + 1);
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        sum += nums[i];
    }
    ll maxgain = 0;
    queue<int> next;
    for (int left = 1; left <= n; left++) {
        int nextLeft = -1;
        ll sum = 0;
        for (int right = left; right <= n; right++) {
            ll gain = 0;
            sum += nums[right];
            int elem = nums[right];
            int currReplace = left + right;
            if (currReplace <= elem) {
                if (left == 1)
                    next.push(right);
            }
            gain = (right - left + 1) * currReplace - sum;
            smax(maxgain, gain);
        }
        if (next.empty()) {
            break;
        }
        nextLeft = next.front();
        next.pop();
        left = nextLeft;
    }
    sum += maxgain;
    cout << sum << endl;
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