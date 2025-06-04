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
    int n;
    cin >> n;
    vector<int> coins(n, 0);
    for (int &coin : coins)
        cin >> coin;
    sort(coins.begin(), coins.end());
    // now construct the table
    ll sum = 0;
    ll odd = 1;
    for (int i = 0; i < n; i++)
    {
        sum += coins[i];
        if (sum > odd)
        {
            cout << (odd - 1);
            return;
        }
        else if (sum == odd)
            odd += 2;
    }
    cout << odd;
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