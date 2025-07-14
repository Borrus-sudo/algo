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
#include <span>

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
    vector<int> a(n + 1, -1); // sentinel value
    vector<int> b(n + 1, -1); // sentinel value
    vector<pair<int, int>> cache(2 * n + 1, pair<int, int>(0, 0));

    for (int &elem : span(a).first(n))
        cin >> elem;
    for (int &elem : span(b).first(n))
        cin >> elem;

    int l_block = 1;
    int elem = a[0];
    for (int i = 1; i < n + 1; i++)
    {
        if (a[i] == a[i - 1])
            l_block++;
        else
        {
            smax(cache[elem].first, l_block);
            l_block = 1;
            elem = a[i];
        }
    }

    l_block = 1;
    elem = b[0];

    for (int i = 1; i < n + 1; i++)
    {
        if (b[i] == b[i - 1])
            l_block++;
        else
        {
            smax(cache[elem].second, l_block);
            l_block = 1;
            elem = b[i];
        }
    }

    auto [island1, island2] = *max_element(all(cache), [](auto a, auto b)
                                           { return (b.first + b.second) > (a.first + a.second); });
    cout << (island1 + island2) << endl;
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