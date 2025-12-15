#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdint>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ff first
#define ss second
#define ll long long
#define pii pair<int, int>
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, a;
        cin >> n >> a;
        vector<ll> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        int l = lower_bound(v.begin(), v.end(), a) - v.begin();
        int r = v.end() - upper_bound(v.begin(), v.end(), a);
        if (l > r)
            cout << a - 1 << endl;
        else
            cout << a + 1 << endl;
    }

    return 0;
}