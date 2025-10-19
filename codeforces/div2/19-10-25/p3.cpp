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

bool factorize(vector<int>& cache, int num) {
    for (int i = 1; i * i <= num; i++) {
        if (num % i == 0) {
            int fact1 = i;
            int fact2 = num / i;
            cache[fact1]++;
            if (fact1 != fact2)
                cache[fact2]++;
            if (cache[fact1] > 1 && fact1 != 1)
                return true;
            if (fact1 != fact2 && cache[fact2] > 1 && fact2 != 1)
                return true;
        }
    }
    return false;
}
void unwind(vector<int>& cache, int num) {
    for (int i = 1; i * i <= num; i++) {
        if (num % i == 0) {
            int fact1 = i;
            int fact2 = num / i;
            cache[fact1]--;
            if (fact1 != fact2)
                cache[fact2]--;
        }
    }
}
bool isGCDBiggerThanOne(vector<int>& cache, int num) {
    for (int i = 1; i * i <= num; i++) {
        if (num % i == 0) {
            int fact1 = i;
            int fact2 = num / i;
            if ((cache[fact1] + 1) > 1 && fact1 != 1)
                return true;
            if (fact1 != fact2 && (cache[fact2] + 1) > 1 && fact2 != 1)
                return true;
        }
    }
    return false;
}

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int& num : nums)
        cin >> num;
    vector<int> costs(n);
    for (int& cost : costs)
        cin >> cost;
    // now factorize all numbers and see
    vector<int> cache(2e5 + 1, 0);
    bool isAnEvenNumberPresent = false;
    for (int num : nums) {
        bool gcdBiggerThanOne = factorize(cache, num);
        if (gcdBiggerThanOne) {
            cout << 0 << endl;
            return;
        }
        if (num % 2 == 0)
            isAnEvenNumberPresent = true;
    }
    if (isAnEvenNumberPresent) {
        cout << 1 << endl;
    } else {
        // yeah kinda problematic
        // I can increase by one and chance arises it works
        // max a 2 man operations
        for (int num : nums) {
            unwind(cache, num);
            bool yes = isGCDBiggerThanOne(cache, num + 1);
            if (yes) {
                cout << 1 << endl;
                return;
            }
            factorize(cache, num);
        }
        cout << 2 << endl;
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