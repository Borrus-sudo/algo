#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <string>
#include <algorithm>
#include <bitset>
#define all(x) (x).begin, (x).end()
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
    ll a, b;
    cin >> a;
    cin >> b;
    ll k1 = a & b;
    cout << k1 << endl;
    ll k2 = k1 >> 1;
    cout << k2 << endl;
    if ((a + b) == (a ^ b))
        cout << 0 << endl;
    else if ((a + b + 2 * k1) == ((a + k1) ^ (b + k1)))
        cout << k1 << endl;
    else if ((a + b + 2 * k2) == ((a + k2) ^ (b + k2)))
        cout << k2 << endl;
    else
        cout << -1 << endl;
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
