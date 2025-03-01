#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <string>
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
#define all(x) (x).begin, (x).end()

void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << -1 << endl;
        return;
    }
    unordered_map<ll, bool> cache;
    ll maxP = (ll)sqrt(n) + 2;
    string res = "2 1 ";
    cache[4] = true;
    cache[1] = true;
    string nextTime = "";
    for (ll i = 3; i <= n; i++)
    {
        if (i <= maxP)
        {
            cache[(ll)(i * i)] = true;
        }
        if ((cache[i / 2] && cache[i + 1] && i % 2 == 0) || (cache[i] && cache[(i + 1) / 2] && (i + 1) % 2 == 0))
        {
            nextTime = to_string(i);
            if (i == n)
            {
                cout << -1 << endl;
                return;
            }
            continue;
        }
        else
        {
            res += (to_string(i) + " ");
        }
        if (nextTime != "")
        {
            res += nextTime + " ";
            nextTime = "";
        }
    }
    if (nextTime != "")
        res += nextTime + " ";
    cout << res;
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int TC = 1;
    cin >> TC;

    while (TC--)
        solve();

    return 0;
}