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
    int n, x;
    cin >> n >> x;
    vector<int> items(n);
    for (int& item : items)
        cin >> item;
    sort(all(items));
    int i = 0, j = n - 1;
    ll currP = 0;
    ll currL = 0;
    ll points = 0;
    vector<int> choices;
    choices.reserve(n);
    while (i <= j) {
        // let's say we make the expensive purchase first
        ll possP = currP + items[j];
        ll newL = possP / x;
        if (newL > currL) {
            // commit
            currL = newL;
            currP = possP;
            points += items[j];
            choices.push_back(items[j]);
            j--;
        } else {
            // so it did not change
            // what to do? Pick up the item that can bring about a change here?
            // or
            currP += items[i];
            choices.push_back(items[i]);
            i++;
        }
    }
    cout << points << "\n";
    for (int choice : choices)
        cout << choice << " ";
    cout << "\n";
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