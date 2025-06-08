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
    int n;
    cin >> n;
    vector<int> states(n, 0);
    for (int &state : states)
        cin >> state;
    // guaranteeed 2
    //
    int a1 = states[0], b1 = 1, c1 = n;
    int a2 = states[1], b2 = 2, c2 = n - 1;
    // see if unique solution is possible
    int det = b1 * c2 - b2 * c1;
    if (!det)
    {
        cout << "NO" << endl;
        return;
    }
    int alphaNum = a1 * c2 - a2 * c1;
    int betaNum = b1 * a2 - b2 * a1;
    if (betaNum % det != 0 || alphaNum % det != 0)
    {
        cout << "NO" << endl;
        return;
    }
    int alpha = alphaNum / det;
    int beta = betaNum / det;

    if (alpha < 0 || beta < 0)
    {
        cout << "NO" << endl;
        return;
    }
    
    for (int i = 2; i < n; i++)
    {
        // crosscheck solution
        int state = states[i];
        int num1 = (i + 1);
        int num2 = n - (i + 1) + 1;
        if (state == (alpha * num1 + beta * num2))
            continue;
        else
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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