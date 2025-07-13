#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
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
const int m = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    string s;

    vector<pair<int, int>> onesMajor;
    ll onesMinorC = 0;

    vector<pair<int, int>> zerosMajor;
    ll zerosMinorC = 0;

    vector<pair<int, int>> ties;
    ll tiesC = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        int zeros = 0;
        int ones = 0;
        for (char c : s)
        {
            if (c == '0')
                zeros++;
            else
                ones++;
        }
        if (ones > zeros)
        {
            zerosMinorC += zeros;
            onesMajor.push_back({ones, zeros});
        }
        else if (ones < zeros)
        {
            onesMinorC += ones;
            zerosMajor.push_back({zeros, ones});
        }
        else
        {
            tiesC += ones;
            ties.push_back({zeros, ones});
        }
    }
    ll costs = 0;
    if (ties.size() || (onesMajor.size() && zerosMajor.size()))
    {
        costs += (onesMinorC + zerosMinorC + tiesC);
    }
    else if (zerosMinorC || onesMinorC) // one dish majority with no ties
    {
        pair<int, int> record;
        ll oc = 0;
        if (onesMajor.size() > zerosMajor.size())
        {
            record = *max_element(all(onesMajor), [](auto a, auto b)
                                  { return (a.first - a.second) > (b.first - b.second); });
            oc = zerosMinorC;
        }
        else if (onesMajor.size() < zerosMajor.size())
        {
            record = *max_element(all(zerosMajor), [](auto a, auto b)
                                  { return (a.first - a.second) > (b.first - b.second); });
            oc = onesMinorC;
        }
        costs = (oc - record.second + record.first);
    }
    cout << costs << endl;
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