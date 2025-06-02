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
    int n;
    cin >> n;
    vector<pair<int, int>> movies(n, {0, 0});
    for (auto &movie : movies)
    {
        cin >> movie.first >> movie.second;
    }
    sort(movies.begin(), movies.end(), [](auto a, auto b)
         { return a.second < b.second; });
    int ans = 1;
    int last = 0;
    for (int i = 1; i < movies.size(); i++)
    {
        if (movies[i].first >= movies[last].second)
        {
            ans++;
            last = i;
        }
    }
    cout << ans << endl;
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