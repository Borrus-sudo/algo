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
    // cout << res;
    vector<int> nums(n, 0);
    for (int &num : nums)
        cin >> num;
    int i = 0;
    int res = 0;
    set<int> win;
    for (int j = 0; j < n; j++)
    {
        if (win.find(nums[j]) == win.end())
        {
            win.insert(nums[j]);
            smax(res, win.size());
        }
        else
        {
            while (i < n && nums[i] != nums[j])
            {
                win.erase(nums[i]);
                i++;
            }
            i++;
        }
    }
    cout << res;
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