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
    int n, k;
    cin >> n >> k;
    queue<int> q;
    for (int i = 1; i <= n; i++)
        q.push(i);
    int not_print = k % q.size();
    while (!q.empty())
    {
        int frontElem = q.front();
        q.pop();
        if (!not_print)
        {
            cout << frontElem << " ";
            if (q.size())
                not_print = k % q.size();
        }
        else
        {
            q.push(frontElem);
            not_print--;
        }
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