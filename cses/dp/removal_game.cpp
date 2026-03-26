#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#define all(x) (x).begin, (x).end()
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
const int m = 1e9 + 7;

pair<int, int> dp(int l, int r, bool turn, pair<int, int> score, vector<int>& a) {
    if (l > r)
        return score;
    if (turn) {
        score.first = max(dp(l + 1, r, !turn, {score.first + a[l], score.second}, a).first,
                          dp(l, r - 1, !turn, {score.first + a[r], score.second}, a).first);
        cout << "First player gets this score " <<  score.first <<  " for " << l << " " << r << endl;
    } else {
        score.second = max(dp(l + 1, r, !turn, {score.first, score.second + a[l]}, a).second,
                           dp(l, r - 1, !turn, {score.first, score.second + a[r]}, a).second);
        cout << "Second player gets this score " << score.second << " for " << l << " " << r << endl;
    }
    return score;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& ai : a)
        cin >> ai;
    cout << dp(0, n - 1, true, {0, 0}, a).first;
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