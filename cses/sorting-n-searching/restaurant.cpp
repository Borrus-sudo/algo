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

struct AbsAscending
{
    bool operator()(int a, int b) const
    {
        return abs(a) < abs(b); 
    }
};

void solve()
{
    // write your code here
    int n;
    cin >> n;
    set<int, AbsAscending> ranges;
    while (n--)
    {
        int start, stop;
        cin >> start >> stop;
        ranges.insert(start);
        ranges.insert(-stop);
    }
    int ans = 0;
    int curr = 0;
    for (int elem : ranges)
    {
        if (elem > 0)
        {
            curr++;
            smax(ans, curr);
        }
        else
        {
            curr--;
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