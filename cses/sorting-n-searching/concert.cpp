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
    int n, m;
    cin >> n >> m;
    multiset<int> tickets;

    while (n--)
    {
        int t;
        cin >> t;
        tickets.insert(t);
    }

    while (m--)
    {
        int customer;
        cin >> customer;
        auto ptr = tickets.upper_bound(customer);
        if (ptr == tickets.begin())
        {
            cout << -1 << endl;
            continue;
        }
        cout << *(--ptr) << endl;
        tickets.erase(ptr);
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