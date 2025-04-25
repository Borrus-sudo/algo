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
    int n, m, l, r;
    cin >> n >> m >> l >> r;
    int reduceHouse = n - m;
    int lnew, rnew;
    if (l + reduceHouse < 0)
    {
        lnew = l + reduceHouse;
        rnew = r;
    }
    else if (l + reduceHouse == 0)
    {
        lnew = 0;
        rnew = r;
    }
    else
    {
        lnew = 0;
        rnew = r - reduceHouse - l;
    }
    cout << lnew << " " << rnew << endl;
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