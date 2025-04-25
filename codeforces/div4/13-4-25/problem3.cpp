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
    int n;
    cin >> n;
    int row = n;
    int col = n;
    vector<int> combo(2 * n + 1, 0);
    int check_sum = 0;
    for (int l = 1; l <= 2 * n; l++)
        check_sum ^= l;
    for (int j = 1; j <= col; j++)
    {
        for (int i = 1; i <= row; i++)
        {
            int elem;
            cin >> elem;
            if (!combo[i + j])
            {
                combo[i + j] = elem;
                check_sum ^= elem;
            }
        }
    }

    combo[1] = check_sum;
    for (int k = 1; k <= 2 * n; k++)
        cout << combo[k] << " ";
    cout << endl;
};

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