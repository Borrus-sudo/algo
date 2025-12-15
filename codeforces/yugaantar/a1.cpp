#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    map<int, int> mp;
    for (auto i : v)
        mp[i]++;
    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        if (mp[v[i]] == 1 && v[i - 1] < v[i] && v[i] > v[i + 1]) {
            int l = 0;
            int j = i;
            while (j > 0 && v[j - 1] < v[j]) {
                l++;
                j--;
            }
            j = i;
            int r = 0;
            while (j < n - 1 && v[j] > v[j + 1]) {
                r++;
                j++;
            }
            ans = max(ans, l + r + 1);
        }
    }
    cout << ans << endl;
}

int main() {
    int TC = 1;
    while (TC--)
        solve();
    return 0;
}