#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <string>
#include <algorithm>
#include <list>
#define all(x) (x).begin, (x).end()
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

void gen_strings(string gen, int idx, vector<string> &results)
{
    if (idx == gen.size())
    {
        results.push_back(gen);
        return;
    }
    for (int i = idx; i < gen.size(); i++)
    {
        swap(gen[idx], gen[i]);
        gen_strings(gen, idx + 1, results);
        swap(gen[idx], gen[i]);
    }
}

void solve()
{
    // write your code here
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    vector<string> results;
    gen_strings(s, 0, results);
    cout << results.size() << endl;
    for (string output : results)
    {
        cout << output << endl;
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