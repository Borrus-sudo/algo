#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool possible(vector<pair<int, int>>& ab, int fuel) {
    int N = ab.size();
    int startFromHere = 0;
    ll curr = fuel;
    for (int i = 0; i < N; i++) {
        if (curr >= ab[i].first) {
            curr += ab[i].second;
            continue;
        }
        startFromHere = (i + 1);
        curr = fuel;
    }
    if (startFromHere >= N) {
        return false;
    }
    curr = fuel;
    int len = N;
    for (int k = 0; k < N; ++k) {
        int i = (startFromHere + k);
        if (i >= N)
            i -= N;
        if (curr < ab[i].first)
            return false;
        curr += ab[i].second;
    }

    return true;
}

void solve() {
    int N;
    cin >> N;
    // vector<int> a(N);
    // vector<int> b(N);
    vector<pair<int, int>> ab(N);

    for (auto& [elem, _] : ab)
        cin >> elem;
    for (auto& [_, elem] : ab)
        cin >> elem;

    int left = 0;
    int right = (1e9);
    int ans = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int fuel = mid;
        if (possible(ab, fuel)) {
            ans = fuel;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << ans << endl;
}

int main() {
    int TC = 1;
    while (TC--)
        solve();
    return 0;
}