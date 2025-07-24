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

void solve()
{
    int n;
    char state;
    string pattern;
    cin >> n >> state >> pattern;
    if (state == 'g')
    {
        cout << 0 << endl;
        return;
    }

    int left;
    for (int i = 0; i < n; i++)
    {
        if (pattern[i] == 'g')
        {
            left = i;
            break;
        }
    }

    int right = -1;
    int maxDist = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (pattern[i] == 'g')
            right = i;
        else if (pattern[i] == state) // now we the closest to right or the one we see in the start
            if (right != -1)
                smax(maxDist, right - i);
            else
                smax(maxDist, n - (i - left));
    }
    cout << (maxDist) << endl;
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