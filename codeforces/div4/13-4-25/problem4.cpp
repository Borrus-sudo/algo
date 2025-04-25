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
    string s1, s2;
    cin >> s1 >> s2;
    int i = 0;
    int j = 0;
    bool res = true;
    while (i < s1.size() && j < s2.size())
    {
        int s1_l = s1.size() - 1 - i;
        int s2_l = s2.size() - 1 - j;
        if (s1[i] != s2[j])
        {
            res = false;
            break;
        }
        if (s1_l == s2_l)
            continue;
        // lens are unequal
        if (s2_l == 0)
        {
            res = false;
            continue;
        }
        if (s2[j + 1] != s1[i])
        {
            j++;
            i++;
            continue;
        }
        
    };

    cout << (res ? "YES" : "NO") << endl;
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