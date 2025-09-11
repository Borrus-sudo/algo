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

vector<vector<int>> findSeqs(vector<int> &inp)
{
    if (inp.size() == 1)
    {
        return {{inp[0]}};
    }
    vector<int> left;
    vector<int> right;

    // INVARIANT: right arr will have always one element and hence res2 will always have one element
    int mid = inp.size() / 2;
    for (int i = 0; i < mid; i++) // Hence, this [0, mid)
    {
        left.push_back(inp[i]);
    }
    for (int j = mid; j < inp.size(); j++) // [mid, inp.size())
    {
        right.push_back(inp[j]);
    }
    vector<vector<int>> res1 = findSeqs(left);
    vector<vector<int>> res2 = findSeqs(right);

    // now the goal is to merge
    vector<vector<int>> merged;
    int start1 = 0, start2 = 0;
    while (start1 < res1.size() && start2 < res2.size())
    {
        if (res1[start1].back() + 1 == res2[start2].front())
        {
            // we can merge them?
            // increment up both
            res1[start1].insert(res1[start1].end(), res2[start2].begin(), res2[start2].end());
            start2++;
        }
        merged.push_back(res1[start1]); // we gotta, you know
        start1++;
    }
    while (start1 < res1.size())
    {
        merged.push_back(res1[start1++]);
    }
    while (start2 < res2.size())
    {
        merged.push_back(res2[start2++]);
    }

    return merged;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int &num : nums)
        cin >> num;
    sort(all(nums));
    int res = findSeqs(nums).size();
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