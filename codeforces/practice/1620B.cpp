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

ll twiceArea(pair<ll, ll> &a, pair<ll, ll> &b, pair<ll, ll> &c)
{
    ll area = abs(a.first * (b.second - c.second) - a.second * (b.first - c.first) + (b.first * c.second - c.first * b.second));
    return area;
}

void solve()
{
    int w, h;
    cin >> w >> h;
    vector<pair<ll, ll>> xA;
    vector<pair<ll, ll>> xP;
    vector<pair<ll, ll>> yA;
    vector<pair<ll, ll>> yP;
    int no;
    cin >> no;
    while (no--)
    {
        int elem;
        cin >> elem;
        xA.push_back({elem, 0});
    }
    cin >> no;
    while (no--)
    {
        int elem;
        cin >> elem;
        xP.push_back({elem, h});
    }
    cin >> no;
    while (no--)
    {
        int elem;
        cin >> elem;
        yA.push_back({0, elem});
    }
    cin >> no;
    while (no--)
    {
        int elem;
        cin >> elem;
        yP.push_back({w, elem});
    }
    // get maximas
    // yA and yP
    ll ans = LONG_MIN;

    pair<ll, ll> maXa = *(xA.rbegin()), miXa = *(xA.begin());
    pair<ll, ll> maXp = *(xP.rbegin()), miXp = *(xP.begin());
    pair<ll, ll> maYa = *(yA.rbegin()), miYa = *(yA.begin());
    pair<ll, ll> maYp = *(yP.rbegin()), miYp = *(yP.begin());

    smax(ans, max(twiceArea(maXa, miXa, maXp), twiceArea(maXa, miXa, miXp)));
    smax(ans, max(twiceArea(maXp, miXp, maXa), twiceArea(maXp, miXp, miXa)));
    smax(ans, max(twiceArea(maYa, miYa, maYp), twiceArea(maYa, miYa, miYp)));
    smax(ans, max(twiceArea(maYp, miYp, maYa), twiceArea(maYp, miYp, miYa)));

    cout << ans << endl;
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