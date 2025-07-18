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
    int n;
    cin >> n;
    // the one with the smallest second number index
    vector<multiset<int>> matrix(n, multiset<int>());
    ll min2_sum = 0;
    ll min1_gl = LONG_MAX;
    ll min2_gl = LONG_MAX;
    for (int i = 0; i < n; i++)
    {
        int size;
        cin >> size;
        int elem;
        while (size--)
        {
            cin >> elem;
            matrix[i].insert(elem);
        }
        int min1 = *(matrix[i].begin());
        int min2 = *next(matrix[i].begin());
        smin(min1_gl, min1);
        smin(min2_gl, min2);
        min2_sum += min2;
    }
    ll res = min2_sum - min2_gl + min1_gl;
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