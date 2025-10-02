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
    int N;
    cin >> N;
    vector<ll> nums(N);
    for (auto &num : nums)
        cin >> num;
    ll ans = 0;
    vector<ll> dp(N);
    for (int i = 0; i < N; i++)
    {
        if (i > 0)
        {
            if (i > 1)
            {
                if (nums[i] < nums[i - 1])
                {
                    dp[i] = dp[i - 1] + (i + 1);
                }
                else
                {
                    dp[i] = dp[i - 2] + (i + 1);
                }
            }
            else
            {
                if (nums[1] > nums[0])
                    dp[1] = 2;
                else
                    dp[1] = 3;
            }
        }
        else
        {
            dp[0] = 1;
        }
        ans += dp[i];
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