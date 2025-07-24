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

int bin_search(vector<tuple<int, int, int>> &cs, int curr_amt)
{
    int left = 0;
    int right = cs.size() - 1;
    int ans = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        auto [l1, r1, real1] = cs[mid];
        if (curr_amt >= real1)
        {
            // worthless
            left = mid + 1;
        }
        else if (curr_amt >= l1 && curr_amt <= r1)
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            // this is ahead
            right = mid - 1;
        }
    }
    return ans;
}

void solve()
{
    int n;
    ll k;
    cin >> n >> k;

    vector<tuple<int, int, int>> cs(n);
    for (auto &[l, r, real] : cs)
        cin >> l >> r >> real;

    vector<bool> used(n, false);

    while (true)
    {
        int idx = -1;
        int max_real = -1;

        for (int i = 0; i < n; ++i)
        {
            auto &[l, r, real] = cs[i];
            if (!used[i] && l <= k && k <= r && real > k)
            {
                if (real > max_real)
                {
                    max_real = real;
                    idx = i;
                }
            }
        }

        if (idx == -1)
            break;

        k = get<2>(cs[idx]);
        used[idx] = true;
    }

    cout << k << '\n';
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