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
    int n;
    cin >> n;

    vector<int> buildingPriors(n, 0);
    vector<int> numberLine(n, 0);
    iota(all(numberLine), 0);

    for (int &prior : buildingPriors)
        cin >> prior;

    sort(all(numberLine), [](auto a, auto b)
         { return buildingPriors[a] >= buildingPriors[b] });
    map<int, int> original2New;
    for (int i = 0; i < n; i++)
    {
        original2New[numberLine[i] - 1] = i;
    }
    cout << 0 << " ";
    for (int i = 0; i < n; i++)
    {
        // cout << (original2New[i] % 2 == 0 ? -(n - original2New[i]) : original2New[i] + 1) << " ";
        
    }
    cout << endl;
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