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
    int n, a;
    cin >> n >> a;
    vector<int> marbles(n);
    for (int& elem : marbles)
        cin >> elem;
    int poss1 = a + 1;
    int poss2 = a - 1;
    int pts1 = 0;
    int pts2 = 0;
    for (int marble : marbles) {
        if (abs(marble - a) > abs(marble - poss1))
            pts1++;
    }
    for (int marble : marbles) {
        if (abs(marble - a) > abs(marble - poss2))
            pts2++;
    }
    if (pts1 > pts2) {
        cout << poss1 << endl;
    } else {
        cout << poss2 << endl;
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