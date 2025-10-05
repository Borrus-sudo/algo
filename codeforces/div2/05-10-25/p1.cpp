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
void smax(S &a, const T &b) {
    if (a < b) a = b;
};

template <typename S, typename T>
void smin(S &a, const T &b) {
    if (a > b) a = b;
};

using ll = long long;
const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    int winnerTeams = (n + 1) / 2;
    int loserTeams = (n) / 2;
    int ans = loserTeams;
    while (!(winnerTeams == 1 && loserTeams == 1)) {
        int wWinnerTeams = (winnerTeams + 1) / 2;
        int lWinnerTeams = winnerTeams / 2;
        int wLoserTeams = (loserTeams + 1) / 2;
        int lLoserTeams = loserTeams / 2;
        ans += (lWinnerTeams);
        ans += (lLoserTeams);
        winnerTeams -= lWinnerTeams;
        loserTeams -= lLoserTeams;
        loserTeams += lWinnerTeams;
    }
    cout << (ans + 1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int TC = 1;
    cin >> TC;

    while (TC--) solve();

    return 0;
}