#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <tuple>
#define all(x) (x).begin, (x).end();
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
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
    vector<bool> choices(n + 1, false);
    vector<vector<pair<bool, int>>> ops;

    while (n--)
    {
        char op1;
        char op2;
        int num1;
        int num2;
        cin >> op1;
        cin >> num1;
        cin >> op2;
        cin >> num2;
        pair<bool, int> p1(op1 == 'x' ? true : false, num1);
        pair<bool, int> p2(op2 == 'x' ? true : false, num2);
        ops.push_back({p1, p2});
    }

    for (int i = ops.size() - 1; i >= 0; i--)
    {
        auto pairs = ops[i];
        auto left = pairs[0];
        auto right = pairs[1];

        if (left.first || right.first)
        {
            if (left.first && right.first && left.second == right.second)
                choices[i] = choices[i + 1];
            else
                choices[i] = left > right;
        }
        else
        {
            choices[i] = choices[i + 1];
        }
    }

    ll left = 1;
    ll right = 1;

    for (int i = 0; i < ops.size(); i++)
    {
        bool choose_left = choices[i + 1];
        ll leftGain = 0;
        ll rightGain = 0;
        pair<bool, int> leftPair = ops[i][0];
        pair<bool, int> rightPair = ops[i][1];

        if (leftPair.first == true)
        {
            leftGain += (leftPair.second - 1) * left;
        }
        else
        {
            leftGain += leftPair.second;
        }

        if (rightPair.first == true)
        {
            rightGain += (rightPair.second - 1) * right;
        }
        else
        {
            rightGain += rightPair.second;
        }
        if (choose_left)
            left += (leftGain + rightGain);
        else
            right += (leftGain + rightGain);
    }

    cout << (left + right) << endl;
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