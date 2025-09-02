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
const int INF = 1e9 + 7;

vector<int> getTop3(vector<int> &arr)
{
    int m1 = -1, m2 = -1, m3 = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        int elem = arr[i];
        if (m1 == -1 || elem > arr[m1])
        {
            m3 = m2;
            m2 = m1;
            m1 = i;
        }
        else if (m2 == -1 || elem > arr[m2])
        {
            m3 = m2;
            m2 = i;
        }
        else if (m3 == -1 || elem > arr[m3])
        {
            m3 = i;
        }
    }
    return {m1, m2, m3};
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);

    for (int &elem : a)
        cin >> elem;
    for (int &elem : b)
        cin >> elem;
    for (int &elem : c)
        cin >> elem;
    int ans = 0;
    for (int x : getTop3(a))
        for (int y : getTop3(b))
            for (int z : getTop3(c))
                if (x != y && y != z && z != x)
                    smax(ans, a[x] + b[y] + c[z]);

    cout << ans << endl;
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