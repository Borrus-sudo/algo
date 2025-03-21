#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <string>
#include <bitset>
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
const int lucky_spot = 42;

void genPaths(int curr, int len_covered, int &result, bitset<49> &history, unordered_map<int, char> compulsions)
{
    len_covered++;
    char compulsion = compulsions[len_covered];
    if ((!compulsion || compulsion == 'D') && (curr + 7) < 49 && history[curr + 7] != 1)
    {
        history[curr + 7] = 1;
        if (curr + 7 == lucky_spot)
        {

            if (len_covered == 48)
            {
                result++;
                cout << "hit" << endl;
                return;
            }
            else
            {
                return;
            }
        }
        genPaths(curr + 7, len_covered, result, history, compulsions);
        history[curr + 7] = 0;
    }
    if ((!compulsion || compulsion == 'U') && (curr - 7) >= 0 && history[curr - 7] != 1)
    {
        history[curr - 7] = 1;
        if (curr - 7 == lucky_spot)
        {

            if (len_covered == 48)
            {
                result++;
                cout << "hit" << endl;

                return;
            }
            else
            {
                return;
            }
        }
        genPaths(curr - 7, len_covered, result, history, compulsions);
        history[curr - 7] = 0;
    }
    if ((!compulsion || compulsion == 'R') && (curr + 1) % 7 != 0 && history[curr + 1] != 1)
    {
        history[curr + 1] = 1;
        if (curr + 1 == lucky_spot)
        {
            if (len_covered == 48)
            {
                result++;
                cout << "hit" << endl;

                return;
            }
            else
            {
                return;
            }
        }
        genPaths(curr + 1, len_covered, result, history, compulsions);
        history[curr + 1] = 0;
    }
    if ((!compulsion || compulsion == 'L') && (curr + 1) % 7 != 1 && history[curr - 1] != 1)
    {
        history[curr - 1] = 1;
        if (curr - 1 == lucky_spot)
        {

            if (len_covered == 48)
            {
                result++;
                cout << "hit" << endl;

                return;
            }
            else
            {
                return;
            }
        }
        genPaths(curr - 1, len_covered, result, history, compulsions);
        history[curr - 1] = 0;
    }
}

void solve()
{
    // write your code here
    string s;
    cin >> s;
    unordered_map<int, char> constraints;
    int results = 0;
    int len = -1;
    int curr = 0;
    bitset<49> history;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != '?')
            constraints[i + 1] = s[i];
    };
    genPaths(0, -1, results, history, constraints);
    cout << results;
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