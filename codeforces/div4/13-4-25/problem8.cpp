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
    int n, q;
    cin >> n;
    cin >> q;
    vector<int> nums;
    nums.reserve(n);
    while (n--)
    {
        int a;
        cin >> a;
        nums.push_back(a);
    }
    while (q--)
    {
        int k, l, r;
        ll ans = 0;
        cin >> k >> l >> r;
        for (int i = l; i <= r; i++)
        {
            if (nums[i - 1] != 1)
                while (k % nums[i - 1] == 0)
                {
                    k /= nums[i - 1];
                }
            ans += k;
        };
        cout << ans << endl;
    }
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