#pragma region
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#ifndef ONLINE_JUDGE
#define endl "\n"
#define dbg(x) cout << "Line(" << __LINE__ << ") -> " << #x << " = " << (x) << endl;
#else
#define endl std::endl
#define dbg
#endif

using namespace std;

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

#define vvi(m, rows, cols): \
    vvi m(rows, vi(cols));  \
    in(m);

#define vvll(m, rows, cols): \
    vvll m(rows, vll(cols)); \
    in(m);

#define ret(...)      \
    out(__VA_ARGS__); \
    return;

#define svec ranges::to<vector>()
#define sstr ranges::to<string>()
#define sort ranges::sort
#define asc ranges::sort
#define desc(vec) ranges::sort(vec, std::greater{});
#define map ranges::views::transform
#define filter ranges::views::filter
#define some ranges::any_of
#define all ranges::all_of
#define none ranges::none_of
#define zip(...) ranges::views::cartesian_product(__VA_ARGS__) | svec
#define drop ranges::views::drop
#define take ranges::views::take
#define chunk ranges::views::chunk
#define slide ranges::views::slide
#define fill ranges::iota
#define bs ranges::binary_search
#define has some
#define contains some
#define slice ranges::views::slice
#define len(r) ranges::distance(r)
#define for(left, right) for (const auto& left : right)
#define pred(...) [&](__VA_ARGS__)
#define cond(...) [&](auto a) { return (__VA_ARGS__) }
#define comp(...) [&](auto a, auto b) { return (__VA_ARGS__) }
#pragma endregion

void solve() {
}

int main() {
    int(TC);
    out(TC);
    while (TC--)
        solve();
    return 0;
}
