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
    ll n, x;
    cin >> n >> x;
    vector<int> fps(n, 0);
    for (int &val : fps)
        cin >> val;
    pair<ll, ll> range(LONG_MAX, LONG_MIN);
    ll ans = 0;

    for (int i = 0; i < n; i++)
    {
        ll locLB = fps[i] - x;
        ll locUP = fps[i] + x;
        smax(range.first, locLB);
        smin(range.second, locUP);
        if (range.first > range.second)
        {
            // MISTMATCH
            range.first = locLB;
            range.second = locUP;
            ans++;
        }
    }

    cout << (ans - 1) << endl;
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