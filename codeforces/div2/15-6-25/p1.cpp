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
    ll k, a, b, x, y;
    cin >> k >> a >> b >> x >> y;
    ll res = 0;
    if (x < y)
    {
        // we cook a
        if (k >= a)
        {
            res += ((k - a) / x);
            k -= (res * x);
            if (k >= a)
            {
                res++;
                k -= x;
            }
        }
        if (k >= b)
        {
            ll lres = ((k - b) / y);
            res += lres;
            k -= (lres * y);
            if (k >= b)
                res++;
        }
    }
    else
    {
        if (k >= b)
        {
            res += ((k - b) / y);
            k -= (res * y);
            if (k >= b)
            {
                res++;
                k -= y;
            }
        }
        if (k >= a)
        {
            ll localRes = ((k - a) / x);
            res += localRes;
            k -= (localRes * x);
            if (k >= a)
                res++;
        }
    }
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