#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <climits>

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
    int n, x;
    cin >> x >> n;
    set<int> posts;
    posts.insert(x);
    while (n--)
    {
        int post;
        cin >> post;
        posts.insert(post);
        // calculate the maxima
        // int prevPost = 0;
        // int maxLen = INT_MIN;
        // for (int post : posts)
        // {
        //     smax(maxLen, post - prevPost);
        //     prevPost = post;
        // }
        // cout << maxLen << endl;
    }
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