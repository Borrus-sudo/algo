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
    ll a, b;
    cin >> a >> b;
    ll res = 0;
    if (a % 2 != 0 && b % 2 != 0) // odd, odd
    {
        res = a * b + 1;
    }
    else if (a % 2 == 0 && b % 2 != 0) // even, odd
    {
        res = -1;
    }
    else if (a % 2 != 0 && b % 4 != 0) // odd, even but even is not a multiple of 4
    {
        res = -1;
    }
    else // if (a % 2 == 0 && b % 2 == 0) // even
    {
        res = a * b / 2 + 2;
    }
    cout << res << endl;
    // else
    // {
    //     // res = a * b / 2
    // } // odd, even but even is alteast a multiple of 4
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