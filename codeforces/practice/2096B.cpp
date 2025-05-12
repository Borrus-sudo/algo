#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>

#define all(x) (x).begin, (x).end()
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
const int m = 1e9 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;
    ll res = 0;
    vector<ll> lefts(n, 0);
    vector<ll> leftover(n, 0);

    for (int i = 0; i < n; i++)
    {
        ll elem;
        cin >> elem;
        lefts[i] = elem;
    }

    for (int i = 0; i < n; i++)
    {
        ll elem;
        cin >> elem;
        res += max(elem, lefts[i]);
        leftover[i] = min(elem, lefts[i]);
    };
    sort(leftover.begin(), leftover.end(), greater<int>());
    for (int i = 0; i < (k - 1); i++)
        res += leftover[i];
    res++;
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