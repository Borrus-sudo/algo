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
    vector<vector<int>> freq(26, vector<int>(n + 1, 0));

    string inp;
    cin >> inp;

    // precompute
    for (int key = 0; key < 26; key++)
    {
        for (int idx = 1; idx <= n; idx++)
        {
            int currChar = inp[idx - 1] - 'a';
            if (key == currChar)
                freq[key][idx] += (freq[key][idx - 1] + 1);
            else
                freq[key][idx] += (freq[key][idx - 1]);
        }
    }

    int maxim = 0;
    for (int idx = 1; idx <= n; idx++)
    {
        // LEFT HALF, RIGHT HALF
        int left = 0;
        int right = 0;
        for (auto prefix : freq)
        {
            left += (prefix[idx - 1] - prefix[0] > 0);
            right += (prefix[n] - prefix[idx - 1] > 0);
        }
        smax(maxim, left + right);
    }
    cout << maxim << endl;
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