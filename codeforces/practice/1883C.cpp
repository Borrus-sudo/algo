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

tuple<int, int> divideOps(vector<int> &nums, int k)
{
    int winnerIdx = 0;
    int currIdx = 0;
    int ops = INT_MAX;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == -1)
            continue;
        int remainder = nums[i] % k;
        if (!remainder)
        {
            return {0, i};
        }
        if (ops <= (k - remainder))
        {
            continue;
        }
        ops = k - remainder;
        winnerIdx = i;
    }
    return {ops == INT_MAX ? m : ops, winnerIdx}; // dirty overflow handling :(
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n, 0);
    for (int &num : nums)
    {
        cin >> num;
    }

    if (k == 4)
    {
        auto [path1, _] = divideOps(nums, 4);
        auto [path21, resIdx] = divideOps(nums, 2);
        nums[resIdx] = -1;
        auto [path22, __] = divideOps(nums, 2);
        int ops = min(path1, path21 + path22);
        cout << ops << endl;
    }
    else
    {
        auto [ops, _] = divideOps(nums, k);
        cout << ops << endl;
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