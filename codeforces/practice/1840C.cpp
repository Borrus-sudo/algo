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
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> temps(n, 0);
    for (int &temp : temps)
        cin >> temp;
    int left = 0;
    ll ans = 0;
    for (int right = 0; right < n; right++)
    {
        if (temps[right] > q)
        {
            left = right;
            while (left < n && temps[++left] > q)
                ;
            right = left - 1; // to nullify for the increase
            continue;
        }
        ans += max(right - left + 1 - k + 1, 0);
    }
    cout << ans << endl;
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