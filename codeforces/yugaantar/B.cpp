#pragma region
#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define endl "\n"
#define dbg(x) cout << "Line(" << __LINE__ << ") -> " << #x << " = " << (x) << endl;
#else
#define endl std::endl
#define dbg
#endif

using namespace std;
namespace rng = std::ranges;
// Basic types

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
template <typename T>
using vec = vector<T>;
using vi = vec<int>;
using vll = vec<ll>;
using vvi = vec<vi>;
using vvll = vec<vll>;
using str = string;
template <typename T>
using minheap = priority_queue<T, vector<T>, std::greater<T>()>;
const int INF = 1e9 + 7;

template <typename T, typename... Types>
void in(T& first, Types... args) {
    if constexpr (is_same<T, pi>::value || is_same<T, pll>::value) {
        in(first.first);
        in(first.second);
    } else if constexpr (is_same<T, vi>::value || is_same<T, vll>::value ||
                         is_same<T, vvi>::value || is_same<T, vll>::value) {
        for (int i = 0; i < first.size(); i++) {
            in(first[i]);
        }
    } else {
        cin >> first;
    }
    if constexpr (sizeof...(args) > 0) {
        in(args...);
    }
}

template <typename T, typename... Types>
void out(T first, Types... args) {
    if constexpr (is_same<T, pi>::value || is_same<T, pll>::value) {
        out(first.first);
        out(first.second);
    } else if constexpr (is_same<T, vi>::value || is_same<T, vll>::value) {
        for (int i = 0; i < first.size(); i++) {
            out(first[i]);
        }
    } else {
        cout << first << " ";
    }
    cout << endl;
    if constexpr (sizeof...(args) > 0) {
        in(args...);
    }
}

void out() {
    cout << endl;
}

template <typename T>
struct vectorizer {
    template <rng::input_range R>
    friend constexpr auto operator|(R&& r, const vectorizer& _) {
        vec<T> arr;

        if constexpr (requires { arr.reserve(rng::size(r)); })
            arr.reserve(rng::size(r));

        for (auto&& x : r) {
            if constexpr (requires { arr.push_back(x); })
                arr.push_back(x);
        }

        return arr;
    }
};

// to<T>() factory
template <typename T>
constexpr auto to() {
    return vectorizer<T>{};
}

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

#define int(...)     \
    int __VA_ARGS__; \
    in(__VA_ARGS__);
#define ll(...)     \
    ll __VA_ARGS__; \
    in(__VA_ARGS__);
#define pi(...)     \
    pi __VA_ARGS__; \
    in(__VA_ARGS__);
#define pll(...)     \
    pll __VA_ARGS__; \
    in(__VA_ARGS__);

#define vi(m, ...)                         \
    vi m = move(vector<int>(__VA_ARGS__)); \
    in(m);
#define vll(m, ...)                        \
    vll m = move(vector<ll>(__VA_ARGS__)); \
    in(m);
#define vvi(m, rows, cols) \
    vvi m(rows, vi(cols)); \
    in(m);
#define vvll(m, rows, cols)  \
    vvll m(rows, vll(cols)); \
    in(m);

#define str(s) \
    string s;  \
    in(s);

#define ret(...)      \
    out(__VA_ARGS__); \
    return;

#define sort rng::sort
#define asc rng::sort
#define desc(vec) rng::sort(vec, std::greater{});
#define sum rng::accumulate
#define cnt rng::count
#define cnt_if rng::count_if
#define fill rng::views::iota
#define bs rng::binary_search
#define len(r) rng::distance(r)

#define map rng::views::transform
#define filter rng::views::filter
#define some rng::any_of
#define all rng::all_of
#define none rng::none_of
#define zip(...) rng::views::cartesian_product(__VA_ARGS__) | svec
#define drop rng::views::drop
#define take rng::views::take
#define drop_while rng::views::drop_while
#define take_while rng::views::take_while
#define chunk rng::views::chunk
#define slide rng::views::slide
#define adj(n) rng::views::adjacent<n>
#define has some
#define contains some
#define rev rng::views::reverse
#define slice rng::views::slice

#define loop(left, right) for (const auto& left : right)
#define pred(...) [&](\__VA_ARGS__)
#define cond(...) [&](auto a) { return (__VA_ARGS__); }
#define comp(...) [&](auto a, auto b) { return (__VA_ARGS__); }
#pragma endregion

bool possible(vi& a, vi& b, int fuel) {
    int N = a.size();
    int startFromHere = 0;
    ll curr = fuel;
    for (int i = 0; i < N; i++) {
        if (curr >= a[i]) {
            curr += b[i];
            continue;
        }
        startFromHere = (i + 1);
        curr = fuel;
    }
    if (startFromHere >= N) {
        return false;
    }
    curr = fuel;
    int len = N;
    for (int k = 0; k < N; ++k) {
        int i = (startFromHere + k);
        if (i >= N)
            i -= N;
        if (curr < a[i])
            return false;
        curr += b[i];
    }

    return true;
}

void solve() {
    int(N);
    vi(a, N);
    vi(b, N);
    int left = 0;
    int right = 1e9;
    int ans = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int fuel = mid;
        if (possible(a, b, fuel)) {
            ans = fuel;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    out(ans);
}

int main() {
    // int(TC);
    int TC = 1;
    while (TC--)
        solve();
    return 0;
}