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
void input(T& first, Types... args) {
    if constexpr (is_same<T, pi>::value || is_same<T, pll>::value) {
        cin >> first.first;
        cin >> first.second;
    } else if constexpr (is_same<T, vi>::value || is_same<T, vll>::value) {
        for (int i = 0; i < first.size(); i++) {
            cin >> first[i];
        }
    } else {
        cin >> first;
    }
    if constexpr (sizeof...(args) > 0) {
        input(args...);
    }
}

template <typename T, typename... Types>
void print(T first, Types... args) {
    if constexpr (is_same<T, pi>::value || is_same<T, pll>::value) {
        cout << first.second << " ";
        cout << first.second << " ";
    } else if constexpr (is_same<T, vi>::value || is_same<T, vll>::value) {
        for (int i = 0; i < first.size(); i++) {
            cout << first[i] << " ";
        }
    } else {
        cout << first;
    }
    cout << endl;
    if constexpr (sizeof...(args) > 0) {
        input(args...);
    }
}

void print() {
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

vi vivec(int n) {
    return vi(n);
}

vi vivec(vi params) {
    return params;
}

vll vllvec(int n) {
    return vll(n);
}

vll vllvec(vll params) {
    return params;
}

#define int(...)     \
    int __VA_ARGS__; \
    input(__VA_ARGS__);

#define ll(...)     \
    ll __VA_ARGS__; \
    input(__VA_ARGS__);

#define pi(...)     \
    pi __VA_ARGS__; \
    input(__VA_ARGS__);

#define pll(...)     \
    pll __VA_ARGS__; \
    input(__VA_ARGS__);

#define vi(m, ...)                   \
    vi m = move(vivec(__VA_ARGS__)); \
    input(m);

#define vll(m, ...)                    \
    vll m = move(vllvec(__VA_ARGS__)); \
    input(m);

#define ret(...)        \
    print(__VA_ARGS__); \
    return;

#define vec ranges::to<vector>()
#define sort ranges::sort
#define asc ranges::sort
#define desc(vec) ranges::sort(vec, std::greater{});
#define map ranges::views::transform
#define filter ranges::views::filter
#define some ranges::any_of
#define all ranges::all_of
#define none ranges::none_of
#define zip(...) ranges::views::cartesian_product(__VA_ARGS__) | vec
#define drop ranges::views::drop
#define take ranges::views::take
#define chunk ranges::views::chunk
#define slide ranges::views::slide
#define fill ranges::iota
#define bs ranges::binary_search
#define has some
#define contains some
#define slice ranges::views::slice
#define fin(left, right) for (const auto& left : right)
#define pred(...) [&](__VA_ARGS__)
#define cond(...) [&](auto a) { return (__VA_ARGS__) }
#define comp(...) [&](auto a, auto b) { return (__VA_ARGS__) }
#pragma endregion

void solve() {
    int(n);
    vi(m, n);
    fin(i, m) {
        print(i);
    }
}

int main() {
    int(TC);
    print(TC);
    while (TC--)
        solve();
    return 0;
}
