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
    ll a, b;
    cin >> a >> b;
    if (b > a)
        swap(a, b);
    // a >= b is maintained
    int ops = 0;
    while (a > b)
    {
        if (a & 1)
            break;
        a >>= 1;
        ops++;
    }
    if (b == a)
    {
        // group it up in 2 and 3
        int ans = 0;
        ans = ops / 3;
        ops = ops % 3;
        ans += ops / 2;
        ops = ops % 2;
        ans += ops;
        ops = ans;
    }
    else
    {
        ops = -1;
    }
    cout << ops << endl;
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