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
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int &num : nums)
        cin >> num;
    int j = n - 2;
    ll res = nums[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        int curr = nums[i];
        int top = nums[i + 1];
        int height = i + 1;
        int debt = 1;
        int relief = min(height, top);
        res += curr - 1;
        if (debt > relief)
        {
            res += (debt);
            res -= relief;
        }
    }
    cout << res << endl;
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