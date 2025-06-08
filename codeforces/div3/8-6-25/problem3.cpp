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
    for (int &st : states)
        cin >> st;
    set<int> depChain;
    set<int> currChain;
    int cuts = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            depChain.insert(states[i]);
            currChain.insert(states[i]);
            continue;
        }
        bool allThere = currChain.size() != 0 ? true : false;
        currChain.insert(states[i]);
        for (int elem : depChain)
            if (currChain.find(elem) == currChain.end())
            {
                allThere = false;
                break;
            }
        if (allThere)
        {
            cuts++;
            depChain.empty();
            for (int curr : currChain)
                depChain.insert(curr);
            currChain.empty();
        }
    }
    cout << (cuts + 1) << endl;
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