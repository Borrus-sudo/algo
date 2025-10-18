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
string num2bin(int a) {
    if (a == 0)
        return "0";
    string s;
    while (a) {
        if (a & 1)
            s = '1' + s;
        else
            s = '0' + s;
        a >>= 1;
    }
    return s;
}

void solve() {
    int a, b;
    cin >> a >> b;
    // if a and b have the same number if of bits life is easy
    string aBin = num2bin(a);
    string bBin = num2bin(b);
    // dbg(aBin);
    // dbg(bBin);
    if (a == b) {
        cout << 0 << endl;
    } else {
        if (aBin.size() == bBin.size()) {
            // int remove2 = stoi(aBin[0] + string(aBin.size() - 1, '0'), nullptr, 2);
            aBin.erase(aBin.begin());  // remove
            bBin.erase(bBin.begin());  // add
            // dbg(aBin);
            // dbg(bBin);
            int remove = stoi(aBin, nullptr, 2);
            int add = stoi(bBin, nullptr, 2);
            cout << 2 << endl;
            cout << remove << " " << add << endl;
            // now we have to choose that character
        } else if (a > b) {
            // we gotta do that but carefully, slice the length
            int diff = aBin.size() - bBin.size();
            int remove2 = stoi(aBin.substr(0, diff) + string(bBin.size(), '0'), nullptr, 2);
            aBin = aBin.substr(diff);
            // dbg(aBin);
            // dbg(bBin);
            int remove = stoi(aBin, nullptr, 2);
            int add = stoi(bBin, nullptr, 2);
            cout << 3 << endl;
            cout << remove << " " << add << " " << remove2 << endl;
        } else {
            cout << -1 << endl;
        }
    }
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