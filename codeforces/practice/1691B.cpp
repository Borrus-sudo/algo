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
    vector<int> shoes(n, 0);
    vector<int> res(n, 0);
    iota(all(res), 1);
    for (int &shoe : shoes)
        cin >> shoe;
    for (int i = 0; i < n; i++)
    {
        if ((i - 1) >= 0 && shoes[i] == shoes[i - 1])
        {
            // we have to construct the order now
            swap(res[i], res[i - 1]);
        }
        else if ((i + 1) < n && shoes[i] == shoes[i + 1])
        {
            continue;
            // we never do a back= 
        }
        else
        {
            // not fine
            cout << -1 << endl;
            return;
        }
    }
    for (int val : res)
        cout << val << " ";
    cout << endl;
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