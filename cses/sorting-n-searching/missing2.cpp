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
    int n, m;
    cin >> n >> m;
    vector<int> posDB(n + 1, -1);
    vector<int> list(n + 1, 0);
    int pos = 1;
    int res = 0;
    while (n--)
    {
        int elem;
        cin >> elem;
        posDB[elem] = pos;
        list[pos] = elem;
        if (posDB[elem - 1] == -1)
            res++;
        pos++;
    }
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        int num1 = list[a];
        int num2 = list[b];
        swap(list[a], list[b]);
        swap(posDB[num1], posDB[num2]);
        // if (posDB[num1 - 1] > posDB[num1] && posDB[])
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