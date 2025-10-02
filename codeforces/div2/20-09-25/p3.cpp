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
#include <numeric>

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
    string s;
    int n;
    cin >> n;
    cin >> s;
    vector<bool> fixedDir(n, false);
    bool pass1 = true;
    bool pass2 = true;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            if (i == 0 || i == n - 1)
                continue;
            if (s[i - 1] == '0' || s[i + 1] == '0')
                continue;
            if (fixedDir[i])
                continue;
            if (s[i + 1] == '1' && i < n - 2 && s[i + 2] == '0')
            {
                fixedDir[i + 2] = true;
                fixedDir[i] = true;
                continue;
            }
            if (s[i - 1] == '1' && i > 1 && s[i - 2] == '0' && !fixedDir[i - 2])
            {
                fixedDir[i - 2] = true;
                fixedDir[i] = true;
                continue;
            }

            pass1 = false;
            break;
        }
    }
    fixedDir = vector<bool>(n, false);
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '0')
        {

            if (i == 0 || i == n - 1)
                continue;
            if (s[i - 1] == '0' || s[i + 1] == '0')
                continue;
            if (fixedDir[i])
                continue;
            if (s[i + 1] == '1' && i < n - 2 && s[i + 2] == '0')
            {
                fixedDir[i + 2] = true;
                fixedDir[i] = true;
                continue;
            }
            if (s[i - 1] == '1' && i > 1 && s[i - 2] == '0' && !fixedDir[i - 2])
            {
                fixedDir[i - 2] = true;
                fixedDir[i] = true;
                continue;
            }

            pass2 = false;
            break;
        }
    }
    if (pass1 || pass2)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
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