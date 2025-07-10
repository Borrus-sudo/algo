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
    string a, b;
    cin >> a >> b;
    int cost = 0;
    bool clutchMode = false;
    for (int i = 0; i < a.size(); i++)
    {
        char c1 = a[i];
        char c2 = b[i];
        if (clutchMode)
        {
            if ((c1 - '0') < 9)
            {
                cout << cost << endl;
                return;
            }
            if ((c2 - '0') > 0)
            {
                cout << cost << endl;
                return;
            }
            cost++;
        }
        else
        {
            if (c2 - c1 > 1)
            {
                cout << cost << endl;
                return;
            }
            else if (c2 - c1 == 1)
            {
                clutchMode = true;
                cost++;
            }
            else
            {
                cost += 2;
            }
        }
    }
    cout << (cost) << endl;
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