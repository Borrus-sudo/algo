#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <string>
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

void solve()
{
    int n, elem;
    cin >> n;
    vector<int> nums;
    while (n--)
    {
        cin >> elem;
        nums.push_back(elem);
    }
    // we have the nums
    int state = nums[0] == 0 ? 0 : 1;
    int zeroCount = state == 0 ? 1 : 0;
    int opCount = 0;
    int offset = 0;
    string ops = "";
    for (int i = 1; i <= nums.size(); i++)
    {
        if (i == nums.size())
        {
            if (state == 0 && opCount != 0)
            {
                int firstPos = (i - zeroCount + 1 - offset);
                int secondPos = (i - offset);
                offset += (secondPos - firstPos);
                ops += (to_string(firstPos + 1) + " " + to_string(secondPos + 1) + "\n");
                opCount++;
                zeroCount = 0;
                state = 1;
            }
        }
        if (state == 0)
        {
            // look out for zeroes
            if (nums[i] == 0)
            {
                zeroCount++;
            }
            else
            {
                int firstPos = (i - zeroCount + 1 - offset);
                int secondPos = (i - offset);
                offset += (secondPos - firstPos);
                ops += (to_string(firstPos + 1) + " " + to_string(secondPos + 1) + "\n");
                opCount++;
                zeroCount = 0;
                state = 1;
            }
        }
        else
        {
            if (nums[i] == 0)
            {
                state = 0;
                zeroCount = 1;
            }
        }
    }

    if (zeroCount == nums.size())
    {

        int half = nums.size() / 2;
        opCount = 3;
        ops += "1 " + to_string(half) + "\n" + to_string(half + 1) + " " + to_string(nums.size()) + "\n" + "1 2\n";
    }
    else if (zeroCount == 1)
    {
    }
    else
    {
        ops += ("1 " + to_string(nums.size() - offset) + "\n");
        opCount++;
    }
    cout << "OPCount: " << opCount << endl;
    cout << ops << endl;
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