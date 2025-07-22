#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <unordered_set>

#define all(x) (x).begin(), (x).end()
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
const int INF = 1e9 + 7;
const int MOD = 998244353;

long long mod_pow(long long base, long long exp, long long mod = MOD)
{
    long long result = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp & 1)
            result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

long long mod_div(long long a, long long b, long long mod = MOD)
{
    return a * mod_pow(b, mod - 2, mod) % mod;
}
long long mod_inverse(long long a, long long mod = MOD)
{
    return mod_pow(a, mod - 2, mod);
}

int bin_search(vector<vector<ll>> recs, ll target)
{
    int left = 0;
    int right = recs.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (recs[mid][0] == target)
        {
            return mid;
        }
        else if (recs[mid][0] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> segs(n, vector<ll>(4, 0));
    vector<ll> success(n + 1, 1);
    vector<ll> failures(n + 1, 1);

    int i = 1;
    for (auto &seg : segs)
    {
        cin >> seg[0] >> seg[1] >> seg[2] >> seg[3];
        success[i] = (mod_div(seg[2], seg[3]) * success[i - 1]) % MOD;
        failures[i] = ((mod_div(seg[3] - seg[2], seg[3])) * failures[i - 1]) % MOD; // work the modular arithmetic out
    }

    sort(all(segs), [](auto a, auto b)
         { return a[0] < b[0]; });

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        // see if it starts at 1, if not just output zero
        // if it does, use binary search to find the next ones
        if (segs[i][0] != 1)
        {
            break;
        }
        else
        {
            // bool nextVal = binar
            ll localAns = 1;
            ll r = segs[i][1];
            localAns *= ((success[i + 1] * mod_inverse(success[i])) % MOD);
            while (true)
            {
                if (r == m)
                {
                    ans += localAns;
                    ans %= MOD;
                    break;
                }
                int idx = bin_search(segs, r);
                // failures have to be accounted for too
                if (idx == -1)
                {
                    break;
                }
                else
                {
                    // remove everything from i to idx - 1
                    localAns *= ((failures[i + 1] * mod_inverse(failures[idx])) % MOD);
                    localAns *= ((success[idx + 1] * mod_inverse(success[idx])) % MOD);
                    r = segs[idx][1];
                }
            }
        }
        // if it is accumalate probability
    }
    cout << ans << endl;
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