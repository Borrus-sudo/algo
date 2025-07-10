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
    int n, p;
    cin >> n >> p;
    vector<int> ppl(n + 1, 0);
    vector<int> costs(n + 1, 0);
    auto cmp = [&costs](int left, int right)
    { return costs[left] > costs[right]; };
    std::priority_queue<int, std::vector<int>, decltype(cmp)> pq(cmp);

    ppl[0] = n;
    costs[0] = p;
    pq.push(0);

    for (int i = 1; i < ppl.size(); i++)
    {
        int reach;
        cin >> reach;
        ppl[i] = reach;
    }
    for (int i = 1; i < costs.size(); i++)
    {
        int cost;
        cin >> cost;
        costs[i] = cost;
        pq.push(i);
    }

    int left = n - 1;
    ll tc = p;
    while (left > 0)
    {
        int leastCostIdx = pq.top();
        int leastCost = costs[leastCostIdx];
        int reach = ppl[leastCostIdx];
        pq.pop();
        if (left > reach)
        {
            tc += ((ll)reach * leastCost);
            left -= reach;
        }
        else
        {
            tc += ((ll)left * leastCost);
            left = 0;
        }
    }
    cout << tc << endl;
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