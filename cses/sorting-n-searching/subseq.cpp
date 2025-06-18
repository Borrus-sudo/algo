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
const int mod = 1e9 + 7;

void solve()
{
    // write your code here
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<int> dp(n + 1, 0);
    dp[0] = 1; // base case: empty subsequence

    unordered_map<int, int> last;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = (2LL * dp[i - 1]) % mod;

        if (last.count(a[i]))
        {
            int j = last[a[i]];
            dp[i] = (dp[i] - dp[j - 1] + mod) % mod;
        }

        last[a[i]] = i;
    }

    cout << dp[n] << endl;
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