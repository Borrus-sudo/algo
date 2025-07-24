#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <unordered_set>

#define all(x) (x).begin(), (x).end()
#define dbg(x) cout << "Line(" << __LINE__ << ") -> " << #x << " = " << (x) << endl;

using namespace std;

template <typename S, typename T>
void smax(S &a, const T &b)
{
    if (a < b)
        a = b;
};

template <typename S, typename T>
void smin(S &a, const T &b)
{
    if (a > b)
        a = b;
};

using ll = long long;
const int INF = 1e9 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;
    k--;
    vector<int> heights(n, 0);
    for (auto &height : heights)
        cin >> height;
    // difference between consecutive towers is less than a certain value
    int initial = heights[k];
    sort(all(heights));
    int idx = lower_bound(all(heights), initial) - heights.begin();
    idx++;
    int diff = initial;
    for (; idx < n; idx++)
        if (heights[idx] - heights[idx - 1] <= diff)
            continue;
        else
        {
            cout << "NO" << endl;
            return;
        }
    cout << "YES" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int TC = 1;
    cin >> TC;

    while (TC--)
        solve();

    return 0;
}