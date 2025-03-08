#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <string>
#include <algorithm>
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

void gen_strings(int idx, string str, vector<string> &results)
{
    if (idx >= str.size())
    {
        results.push_back(str);
        return;
    }
    for (int i = idx; i < str.size(); i++)
    {
        string thisIter = str;
        if (i == idx || str[i] != str[i - 1])
        {
            // perform rotation;
            char c = thisIter[i];
            thisIter.erase(i, 1);
            thisIter.insert(idx, 1, c);
            gen_strings(idx + 1, thisIter, results);
        }
    }
}

void solve()
{
    // write your code here
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    vector<string> results = {};
    gen_strings(0, s, results);
    cout << results.size() << endl;
    for (auto entry : results)
        cout << entry << endl;
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