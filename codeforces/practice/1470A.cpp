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

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
template <typename T>
using vec = vector<T>;
using vi = vec<int>;
using vll = vec<ll>;
using vvi = vec<vi>;
using vvll = vec<vll>;
using si = set<int>;
using sll = set<ll>;
using str = string;
template <typename T>
using minheap = priority_queue<T, vector<T>, std::greater<T>>;
const int INF = 1e9 + 7;

template <typename>
struct is_pair_t : false_type {};
template <typename A, typename B>
struct is_pair_t<pair<A, B>> : true_type {};

template <typename>
struct is_vec_t : false_type {};
template <typename T>
struct is_vec_t<vector<T>> : true_type {};

template <typename T, typename... Types>
void in(T& first, Types&... args) {
    if constexpr (is_pair_t<T>::value) {
        in(first.first);
        in(first.second);
    } else if constexpr (is_vec_t<T>::value) {
        for (auto&& elem : first)
            in(elem);
    } else {
        cin >> first;
    }
    if constexpr (sizeof...(args) > 0) {
        in(args...);
    }
}

template <typename T, typename... Types>
void _out(const T& first, const Types&... args) {
    if constexpr (is_pair_t<T>::value) {
        _out(first.first);
        _out(first.second);
    } else if constexpr (is_vec_t<T>::value) {
        for (auto&& elem : first) {
            _out(elem);
        }
    } else {
        cout << first << " ";
    }
    if constexpr (sizeof...(args) > 0) {
        _out(args...);
    }
}

void out() {
    cout << endl;
}

template <typename T, typename... Types>
void out(const T& first, const Types&... args) {
    _out(first, args...);
    out();
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

template <typename T>
constexpr auto to() {
    return vectorizer<T>{};
}

template <typename S, typename T>
void smax(S& a, const T& b) {
    if (a < b)
        a = b;
}

template <typename S, typename T>
void smin(S& a, const T& b) {
    if (a > b)
        a = b;
}

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

#define pref(a)                                                                                   \
    vec<conditional_t<is_same<decltype(a)::value_type, int>::value, ll, decltype(a)::value_type>> \
        pref_##a(a.size() + 1);                                                                   \
    for (int i = 1; i <= a.size(); i++)                                                           \
        pref_##a[i] = pref_##a[i - 1] + a[i - 1];

#define sort rng::sort
#define asc sort
#define desc(vec) sort(vec, std::greater{})
#define sum rng::accumulate
#define cnt rng::count
#define cnt_if rng::count_if
#define bs rng::binary_search
#define len(r) rng::distance(r)
#define copy(src, dest) rng::copy(src, back_inserter(dest))
#define maxe(vec) *(rng::max_element(vec))
#define mine(vec) *(rng::min_element(vec))
#define maxi(vec) (rng::max_element(vec) - vec.begin())
#define mini(vec) (rng::min_element(vec) - vec.begin())
#define some rng::any_of
#define all rng::all_of
#define none rng::none_of
#define iall(x) (x).begin(), (x).end()

#define fill rng::views::iota
#define transform rng::views::transform
#define filter rng::views::filter
#define zip(...) rng::views::cartesian_product(__VA_ARGS__)
#define drop rng::views::drop
#define take rng::views::take
#define drop_while rng::views::drop_while
#define take_while rng::views::take_while
#define chunk rng::views::chunk
#define slide rng::views::slide
#define adj(n) rng::views::adjacent<n>
#define rev rng::views::reverse
#define slice rng::views::slice

#define loop(left, right) for (auto& left : right)
#define uni(...) [&](auto a) { return (__VA_ARGS__); }
#define bi(...) [&](auto a, auto b) { return (__VA_ARGS__); }
#define poly(...) [&](__VA_ARGS__)
#define rep(i, len) for (int i = 0; i < len; i++)
#define rrep(i, len) for (int i = len - 1; i >= 0; i--)
#define iter(i, start, stop, jump) for (int i = start; i < stop; i += jump)
#define riter(i, start, stop, jump) for (int i = start - 1; i >= stop; i -= jump)
#pragma endregion

void solve() {
    int(n, m);
    vi(k, n);
    vi(c, m);  // non-decreasing order
    desc(k);
    int ground = 0;
    ll cost = 0;
    for (int lvl : k) {
        int minGift = ground == len(c) ? INT_MAX : c[ground];
        int alternateGift = c[lvl - 1];
        if (minGift < alternateGift) {
            cost += minGift;
            ground++;
        } else {
            cost += alternateGift;
        }
    }
    out(cost);
}

int main() {
    int(TC);
    while (TC--)
        solve();
    return 0;
}