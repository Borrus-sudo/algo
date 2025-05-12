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
    string p, s;
    cin >> p >> s;

    int j = 0;
    int currLen = 0;

    for (int i = 0; i < p.size(); i++)
    {
        if ((i + 1) < p.size() && p[i] == p[i + 1])
        {
            currLen++;
            continue;
        }
        else
        {
            currLen++;
            char currStroke = p[i];
            int start = j;
            while (j < s.size() && s[j] == currStroke)
                j++;
            int heardLen = j - start;
            if (currLen <= heardLen && heardLen <= 2 * currLen)
            {
            }
            else
            {
                cout << "NO" << endl;
                return;
            }
            currLen = 0;
        }
    }
    cout << (j == s.size() ? "YES" : "NO") << endl;
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