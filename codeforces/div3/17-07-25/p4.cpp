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
    int n, k;
    cin >> n >> k;
    vector<tuple<int, int, int>> cs(n, tuple<int, int, int>(0, 0, 0));
    for (auto &[a, b, c] : cs)
    {
        cin >> a >> b >> c;
    }
    sort(all(cs), [](auto v1, auto v2)
         {
              auto &[a1, b1, c1] = v1;
              auto &[a2, b2, c2] = v2;
              if (a1 < a2)
                  return true;
              if (a1 == a2)
                  return c1 < c2;

              return false; });

    int hopIdx = bin_search(cs, k);
    while (hopIdx != -1)
    {
        k = get<2>(cs[hopIdx]);
        hopIdx = bin_search(cs, k);
    }
    cout << k << endl;
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