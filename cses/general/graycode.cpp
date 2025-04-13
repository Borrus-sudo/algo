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

vector<string> gen(vector<string> span, int currLevel, int toReach)
{
    if (currLevel == toReach)
        return span;
    vector<string> result;
    for (int i = 0; i < span.size(); i++)
    {
        char firstElem = i & 1 ? '1' : '0';
        char secondElem = i & 1 ? '0' : '1';
        result.push_back(span[i] + firstElem);
        result.push_back(span[i] + secondElem);
    }
    return gen(result, ++currLevel, toReach);
}

void solve()
{
    // write your code here
    int depth;
    cin >> depth;
    vector<string> results = gen({"0", "1"}, 1, depth);
    for (auto str : results)
        cout << str << endl;
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
