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
    // write your code here
    int n, x;
    cin >> n >> x;
    vector<int> sorted(n, 0);
    vector<int> og(n, 0);
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        sorted[i] = val;
        og[i] = val;
    }
    sort(sorted.begin(), sorted.end());
    int i = 0, j = sorted.size() - 1;
    while (i < j)
    {
        if (sorted[i] + sorted[j] == x)
            break;
        if (sorted[i] + sorted[j] > x)
            j--;
        else
            i++;
    }
    if (sorted[i] + sorted[j] == x && i != j)
    {
        int k1 = -1;
        int k2 = -1;
        for (int k = 0; k < og.size(); k++)
        {
            if (k1 != -1 && k2 != -1)
                break;
            if (k1 == -1 && og[k] == sorted[i])
            {
                k1 = k;
                continue;
            }
            if (k2 == -1 && og[k] == sorted[j])
            {
                k2 = k;
                continue;
            }
        }
        cout << min(k1, k2) + 1 << " " << max(k1, k2) + 1;
    }
    else
    {
        cout << "IMPOSSIBLE";
    }
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