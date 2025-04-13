#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
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

ll binary_exponentiation(ll a, ll b)
{
    ll res = 1;
    while (b != 0)
    {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

void solve()
{
    // write your code here
    int n;
    cin >> n;
    cout << binary_exponentiation(2, n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int TC = 1;
    // cin >> TC;

    while (TC--)
        solve();

    return 0;
}