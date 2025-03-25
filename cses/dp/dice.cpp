#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
const int m = 1e9 + 7;

int combo(int sum, vector<int> &dp)
{
    if (sum < 0)
        return 0;
    if (sum == 0)
        return 1;
    if (dp[sum] != -1)
        return dp[sum];

    int res = 0;
    for (int i = 1; i <= 6; i++)
    {
        res = (res + combo(sum - i, dp)) % m;
    }
    return dp[sum] = res;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> cache(n + 1, -1);
    cout << combo(n, cache);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int TC = 1;
    while (TC--)
        solve();

    return 0;
}
