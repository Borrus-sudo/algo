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
const int m = 1e9 + 7;

void solve()
{
    int n, d;
    cin >> n >> d;
    vector<pair<int, int>> elems;
    for (int i = 0; i < n; i++)
    {
        int elem;
        cin >> elem;
        elems.push_back({elem, i});
    }
    sort(all(elems), [d](auto a, auto b)
         { 
        int dist1 = a.first % d;
        int dist2 = b.first % d;
        if (dist1 == dist2)
            return a.second < b.second;
        if (dist1 == 0)
            return true;
        if (dist2 == 0)
            return false;
          else
            return dist1 > dist2; });

    for (auto &[_, idx] : elems)
        cout << (idx + 1) << " ";

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