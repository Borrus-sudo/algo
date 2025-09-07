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
    int n;
    cin >> n;
    vector<int> nums(n);
    vector<int> freq(n + 1);
    for (int &num : nums)
        cin >> num;
    // freq arr
    string res = "";
    for (int num : nums)
    {
        freq[num]++;
    }
    // enough characters too
    for (int num : nums)
    {
        if (freq[num] % num != 0)
        {
            cout << -1 << endl;
            return;
        }
    }
    // all clear
    int cnt = 1;
    vector<int> attachChar(n + 1);
    for (int num : nums)
    {
        if (freq[num] % num == 0)
        {
            attachChar[num] = (cnt);
            cnt++;
        }
        freq[num]--;
        res += to_string(attachChar[num]) + " ";
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