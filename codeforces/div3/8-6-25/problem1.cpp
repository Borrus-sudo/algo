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
    int n, x;
    cin >> n >> x;
    vector<int> states(n, 0);
    for (int &state : states)
        cin >> state;
    // first door
    int first = -1;
    int second = -1;
    for (int i = 0; i < states.size(); i++)
    {
        if (states[i] == 1)
        {
            first = i;
            break;
        }
    }
    if (first == -1)
    {
        cout << "YES" << endl;
        return;
    }
    for (int i = states.size() - 1; i >= 0; i--)
    {
        if (states[i] == 1)
        {
            second = i;
            break;
        }
    }
    int number = second - first + 1;
    if (number <= x)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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