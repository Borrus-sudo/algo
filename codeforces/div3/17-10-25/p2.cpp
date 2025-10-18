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

#define all(x) (x).begin(), (x).end()
#define dbg(x) cout << "Line(" << __LINE__ << ") -> " << #x << " = " << (x) << endl;

using namespace std;

template <typename S, typename T>
void smax(S& a, const T& b) {
    if (a < b)
        a = b;
};

template <typename S, typename T>
void smin(S& a, const T& b) {
    if (a > b)
        a = b;
};

using ll = long long;
const int INF = 1e9 + 7;

bool isIncreasing(string s) {
    int prev = -1;
    for (int i = 0; i < s.size(); i++) {
        if (prev <= s[i] - '0') {
            prev = s[i] - '0';
        } else {
            return false;
        }
    }
    return true;
}

bool isPalindrome(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != s[s.size() - i - 1])
            return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < (1 << n); i++) {
        string subseq = "";
        string palindrome = "";
        vector<int> indices;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                subseq += s[j];
                indices.push_back(j + 1);
            } else
                palindrome += s[j];
        }
        if (isIncreasing(subseq) && isPalindrome(palindrome)) {
            cout << indices.size() << endl;
            for (int idx : indices)
                cout << idx << " ";
            cout << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int TC = 1;
    cin >> TC;

    while (TC--)
        solve();

    return 0;
}