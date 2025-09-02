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
#include <numeric>

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
    ll n, x, y;
    cin >> n >> x >> y;
    ll cmn = n / lcm(x, y);
    ll a = (n / x);
    ll b = (n / y);

    a -= cmn;
    b -= cmn;
    // give a the max most numbers
    // give b the min most numbers
    ll sum = n * (n + 1) / 2;
    ll max = sum - ((n - a) * (n - a + 1) / 2);
    ll min = b * (b + 1) / 2;
    ll res = max - min;
    cout << res << endl;
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