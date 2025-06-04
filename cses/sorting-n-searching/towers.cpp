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
    vector<int> towers(n, 0);
    vector<int> bases;
    while (n--)
    {
        int cube;
        cin >> cube;
        if (!bases.size())
        {
            bases.push_back(cube);
        }
        else
        {
            auto pos = upper_bound(bases.begin(), bases.end(), cube);
            if (pos == bases.end())
            {
                bases.push_back(cube);
            }
            else
            {
                *pos = cube;
            }
        }
    }
    cout << bases.size() << endl;
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