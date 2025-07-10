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
    vector<set<int>> matrix(n, set<int>());
    for (int i = 0; i < n; i++)
    {
        int rowSize;
        cin >> rowSize;
        while (rowSize--)
        {
            int elem;
            cin >> elem;
            matrix[i].insert(elem);
        }
    }
    // figure out the max elems

    int globalMinIdx = 0;
    int globalMin = *(matrix[globalMinIdx].begin());
    int secondElemMinIdx = 0;
    int secondElemMin = *next(matrix[secondElemMinIdx].begin());

    for (int i = 1; i < n; i++)
    {
        int localOpt1 = *(matrix[i].begin());
        if (localOpt1 < globalMin)
        {
            globalMinIdx = i;
            globalMin = localOpt1;
        }

        int localOpt2 = *next(matrix[i].begin());
        if (localOpt2 < secondElemMin)
        {
            secondElemMinIdx = i;
            secondElemMin = localOpt2;
        }
    }

    matrix[globalMinIdx].erase(globalMin);
    matrix[secondElemMinIdx].insert(globalMin);
    // globalMinIdx = secondElemMinIdx;

    ll tc = 0;

    for (int i = 0; i < n; i++)
    {
        if (i == secondElemMinIdx)
        {
            tc += globalMin;
            continue;
        }
        if (i == globalMinIdx)
        {
            tc += *(matrix[i].begin());
            continue;
        }
        tc += *next(matrix[i].begin()); // guaranteed by the constraint sizes
    }

    cout << tc << endl;
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