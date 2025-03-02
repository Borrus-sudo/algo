#include <iostream>
#include <vector>
#include <unordered_map>
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
#define all(x) (x).begin, (x).end()

string repeat(char c, int times)
{
    string res;
    while (times--)
        res += c;
    return res;
};

void solve()
{
    string s;
    cin >> s;
    int freq_count[26] = {};
    vector<short> used;
    for (char c : s)
    {
        short key = c - 'A';
        if (!freq_count[key])
            used.push_back(key);
        freq_count[key]++;
    }
    string prefix = "";
    string suffix = "";
    string middle = "";
    for (auto key : used)
    {
        if (freq_count[key] % 2 == 1)
        {
            if (middle != "")
            {
                cout << "NO SOLUTION";
                return;
            }
            middle = repeat(key + 'A', freq_count[key]);
        }
        else
        {
            string payload = repeat(key + 'A', freq_count[key] / 2);
            prefix += payload;
            suffix = payload + suffix;
        }
    }
    cout << prefix + middle + suffix;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int TC = 1;
    // cin >> TC;

    while (TC--)
        solve();

    return 0;
}