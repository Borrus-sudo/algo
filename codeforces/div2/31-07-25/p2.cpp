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
#include <numeric>

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
    int n, s;
    cin >> n >> s;
    vector<int> nums(n, 0);
    int ones = 0;
    int twos = 0;
    int zeros = 0;
    for (int &num : nums)
    {
        cin >> num;
        if (num == 1)
            ones++;
        if (num == 2)
            twos++;
        if (num == 0)
            zeros++;
    }
    int sum = accumulate(all(nums), 0);
    if (s < sum)
    {
        // impossible in all cases
        for (int num : nums)
            cout << num << " ";
    }
    else if (sum == s)
    {
        // always possible
        cout << -1;
    }
    else if ((s - sum) % 2 != 0) // odd number
    {
        if ((s - sum) != 1)
            cout << -1;
        else // shit
        {
            while (zeros--)
                cout << 0 << " ";
            while (twos--)
                cout << 2 << " ";
            while (ones--)
                cout << 1 << " ";
        }
    }
    // else
    // {
    //     if (ones >= 2)
    //     {
    //         cout << -1;
    //     }
    //     else if (twos >= 2)
    //     {
    //         if (s - sum > 2)
    //         {
    //             cout << -1;
    //         }
    //         else
    //         {
    //             while (zeros--)
    //                 cout << (0) << " ";
    //             while (twos--)
    //                 cout << 2 << " ";
    //             while (ones--)
    //             {
    //                 cout << (2) << " " << (1) << " ";
    //                 twos--;
    //             }
    //         }
    //     }
    //     // if (twos == ones || (twos - ones) == 1)
    //     // {
    //     //     // shit
    //     //     while (zeros--)
    //     //         cout << (0) << " ";
    //     //     while (ones--)
    //     //     {
    //     //         cout << (2) << " " << (1) << " ";
    //     //         twos--;
    //     //     }
    //     //     while (twos--)
    //     //         cout << 2 << " ";
    //     // }
    //     // else if (twos - ones >= 2)
    //     // {
    //     //     if (s - sum != 2)
    //     //     {
    //     //         cout << -1;
    //     //     }
    //     //     else
    //     //     {
    //     //         // shit
    //     //         while (zeros--)
    //     //             cout << (0) << " ";
    //     //         while (ones--)
    //     //         {
    //     //             cout << (2) << " " << (1) << " ";
    //     //             twos--;
    //     //         }
    //     //         while (twos--)
    //     //             cout << 2 << " ";
    //     //     }
    //     // }
    else
    {
        cout << -1;
    }
    cout << endl;
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