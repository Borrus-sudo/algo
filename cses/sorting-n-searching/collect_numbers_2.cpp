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
    int n, m;
    cin >> n >> m;
    vector<int> elem(n + 2, 0);
    vector<int> idx(n + 2, -1);
    int rounds = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> elem[i];
        idx[elem[i]] = i;
        if (idx[elem[i] - 1] == -1)
        {
            rounds++;
        }
    }
    idx[n + 1] = n + 1;

    while (m--)
    {
        int idx1, idx2;
        cin >> idx1 >> idx2;
        // we have to swap these both
        int elem1 = elem[idx1];
        int elem2 = elem[idx2];
        int s = min(elem1, elem2);
        int b = max(elem1, elem2);

        // preconditions
        bool ss = idx[s] - idx[s - 1] > 0;
        bool bs = idx[s] - idx[s + 1] < 0;
        bool sb = idx[b] - idx[b - 1] > 0;
        bool bb = idx[b] - idx[b + 1] < 0;

        swap(elem[idx1], elem[idx2]);
        swap(idx[elem[idx1]], idx[elem[idx2]]);

        bool pss = idx[s] - idx[s - 1] > 0;
        bool pbs = idx[s] - idx[s + 1] < 0;
        bool psb = idx[b] - idx[b - 1] > 0;
        bool pbb = idx[b] - idx[b + 1] < 0;

        rounds += (ss - pss);
        rounds += (bs - pbs);
        if ((s + 1) != b)
            rounds += (sb - psb);
        rounds += (bb - pbb);

        cout << rounds << endl;

        // we need to check if it exists
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