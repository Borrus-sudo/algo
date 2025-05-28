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
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> applicants(n, 0);
    vector<ll> apartments(m, 0);

    for (auto &applicant : applicants)
        cin >> applicant;
    for (auto &aparment : apartments)
        cin >> aparment;

    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());

    int i = 0;
    int res = 0;
    for (auto person : applicants)
    {
        if (i >= apartments.size())
            break;
        while (i < apartments.size() && apartments[i] <= person + k)
        {
            // check if this is valid
            if (person - k <= apartments[i])
            {
                // valid
                res++;
                i++;
                break;
            }
            i++;
        }
    }

    cout << res << endl;
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