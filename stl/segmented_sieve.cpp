#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>

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
const int N = 1e6;
bool sieve[N + 1];

void createSieve()
{
    for (int i = 1; i <= N; i++)
    {
        sieve[i] = true;
    }

    for (int i = 2; i * i <= N; i++)
    {
        if (sieve[i])
            for (int j = i * i; j <= N; j++)
                sieve[j] = false;
    }
};

vector<int> genPrimes(int num)
{
    vector<int> primes;
    for (int i = 1; i <= num; i++)
    {
        if (sieve[i])
            primes.push_back(i);
    }
}

void solve()
{
    // write your code here
    int l, r;
    cin >> l >> r;
    vector<int> primes = genPrimes(sqrt(r));

    int calc[r - l + 1];

    for (auto prime : primes)
    {
        // start sieving out the composite numbers
        int firstMultiple = (l / prime) * prime;
        if (firstMultiple < l)
            firstMultiple += prime;
        for (int i = max(firstMultiple, prime * prime); i <= r; i += prime) {
            
        }
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