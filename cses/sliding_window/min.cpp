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

void solve()
{
    int n, k;
    cin >> n >> k;
    int x, a, b, c;
    cin >> x >> a >> b >> c;

    vector<ll> arr(n, 0);
    arr[0] = x;
    for (int i = 1; i < n; i++)
    {
        arr[i] = (arr[i - 1] * a + b) % c;
    }

    deque<int> dq;

    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && arr[dq.back()] >= arr[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    ll res = arr[dq.front()];

    for (int i = k; i < n; i++)
    {
        if (dq.front() == i - k)
            dq.pop_front();
        while (!dq.empty() && arr[dq.back()] >= arr[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        res ^= arr[dq.front()];
    }

    cout << (res) << endl;
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