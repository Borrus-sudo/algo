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
    // write your code here
    int n, x;
    cin >> n;
    cin >> x;
    int temp = n;
    int running = 0;
    int curr;
    while (temp--)
    {
        cin >> curr;
        running += curr;
    }
    if (running % n == 0 && (running / n) == x)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
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