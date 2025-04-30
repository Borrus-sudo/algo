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
const int N = 1e6;
int spf[N + 1];

void createSieve()
{
    for (int i = 1; i <= N; i++)
    {
        spf[i] = i;
    }

    for (int i = 2; i * i <= N; i++)
    {
        if (spf[i] == i)
        {
            // prime number
            for (int j = i * i; j <= N; j += i)
            {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    while (n != 1)
    {
        cout << spf[n] << " ";
        n /= spf[n];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int TC = 1;
    // cin >> TC;
    createSieve();
    while (TC--)
        solve();

    return 0;
}