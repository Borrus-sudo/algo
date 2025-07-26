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
    int n, r, b;
    cin >> n >> r >> b;
    string s;
    int redCycles = r / b;
    int leftOverReds = r - redCycles * b;

    int part1 = redCycles / 2;
    int part2 = redCycles - part1;

    int lastPart1 = (redCycles + leftOverReds) / 2;
    int lastPart2 = (redCycles + leftOverReds) - lastPart1; // the previous red cycles

    while (b != 0)
    {
        if (b != 1)
        {
            s += string(part1, 'R');
            s += 'B';
            s += string(part2, 'R');
        }
        else
        {
            s += string(lastPart1, 'R');
            s += 'B';
            s += string(lastPart2, 'R');
        }
        b--;
    }
    cout << s << endl;
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