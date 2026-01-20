#pragma region
#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define endl "\n"
#define dbg(...)                                                     \
    cout << "Line(" << __LINE__ << ") -> " << #__VA_ARGS__ << " = "; \
    out(__VA_ARGS__);
#else
#define endl std::endl
#define dbg
#endif

using namespace std;
namespace rng = std::ranges;
using namespace rng::views;

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
template <typename T>
using maxheap = priority_queue<T>;
const int INF = 1e9 + 7;

template <typename>
struct is_pair_t : false_type {};
template <typename A, typename B>
struct is_pair_t<pair<A, B>> : true_type {};

template <typename>
struct is_vec_t : false_type {};
template <typename T>
struct is_vec_t<vector<T>> : true_type {};

template <typename>
struct is_set_t : false_type {};
template <typename T>
struct is_set_t<set<T>> : true_type {};

template <typename>
struct is_tuple_t : false_type {};
template <typename... Types>
struct is_tuple_t<tuple<Types...>> : true_type {};

template <typename T>
concept is_char_array_v = is_array_v<T> && is_same_v<remove_extent_t<T>, char>;

template <typename T, typename... Types>
void in(T& first, Types&... args) {
    using K = remove_cvref_t<T>;
    if constexpr (is_pair_t<K>::value) {
        in(first.first);
        in(first.second);
    } else if constexpr (is_vec_t<K>::value) {
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
    using K = remove_cvref_t<T>;
    if constexpr (is_pair_t<K>::value) {
        _out(first.first);
        _out(first.second);
    } else if constexpr (std::ranges::range<K> && !is_same_v<K, string> && !is_char_array_v<K>) {
        for (auto&& elem : first) {
            _out(elem);
        }
    } else {
        if constexpr (is_same_v<K, float>)
            cout << std::setprecision(std::numeric_limits<float>::max_digits10) << first << " ";
        else if constexpr (is_same_v<K, double>)
            cout << std::setprecision(std::numeric_limits<double>::max_digits10) << first << " ";
        else
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
template <typename T>
    requires is_pair_t<remove_cvref_t<T>>::value || is_set_t<remove_cvref_t<T>>::value ||
             is_vec_t<remove_cvref_t<T>>::value || is_tuple_t<remove_cvref_t<T>>::value
auto f(T& container) {
    using K = remove_cvref_t<T>;
    if constexpr (is_pair_t<K>::value) {
        return container.first;
    } else if constexpr (is_set_t<K>::value) {
        return *(container.begin());
    } else if constexpr (is_vec_t<K>::value) {
        return container.front();
    } else if constexpr (is_tuple_t<K>::value) {
        return get<0>(container);
    }
}

template <typename T>
    requires is_pair_t<remove_cvref_t<T>>::value || is_set_t<remove_cvref_t<T>>::value ||
             is_vec_t<remove_cvref_t<T>>::value || is_tuple_t<remove_cvref_t<T>>::value
auto b(T& container) {
    using K = remove_cvref_t<T>;
    if constexpr (is_pair_t<K>::value) {
        return container.second;
    } else if constexpr (is_set_t<K>::value) {
        return *(container.rbegin());
    } else if constexpr (is_vec_t<K>::value) {
        return container.back();
    } else if constexpr (is_tuple_t<K>::value) {
        constexpr size_t N = std::tuple_size_v<K>;
        return get<N - 1>(container);
    }
}

unordered_map<str, int> _nextCache;
template <typename T>
T _nextElem(vec<T>& container, str&& identifier) {
    int& next = _nextCache[identifier];
    auto val = container[next];
    next += 1;
    next %= container.size();
    return val;
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
#define vi(m, ...)                      \
    vi m = move(vec<int>(__VA_ARGS__)); \
    in(m);
#define vll(m, ...)                     \
    vll m = move(vec<ll>(__VA_ARGS__)); \
    in(m);
#define vvi(m, rows, cols) \
    vvi m(rows, vi(cols)); \
    in(m);
#define vvll(m, rows, cols)  \
    vvll m(rows, vll(cols)); \
    in(m);
#define str(s) \
    str s;     \
    in(s);
#define vs(m, ...)                            \
    vec<str> m = move(vec<str>(__VA_ARGS__)); \
    in(m);
#define ret(...)      \
    out(__VA_ARGS__); \
    return;

#define pfx(a)                                                                                    \
    vec<conditional_t<is_same<decltype(a)::value_type, int>::value, ll, decltype(a)::value_type>> \
        pref_##a(a.size() + 1);                                                                   \
    for (int i = 1; i <= a.size(); i++)                                                           \
        pref_##a[i] = pref_##a[i - 1] + a[i - 1];

#define sort rng::sort
#define asc sort
#define desc(vec) sort(vec, std::greater{})
#define accumulate(vec, ...) std::accumulate(iall(vec), __VA_ARGS__)
#define cnt rng::count
#define cnt_if rng::count_if
#define bs rng::binary_search
#define len(r) static_cast<int>(rng::distance(r))
#define copy(src, dest) rng::copy(src, back_inserter(dest))
#define maxe(vec) *(rng::max_element(vec))
#define mine(vec) *(rng::min_element(vec))
#define maxi(vec) (rng::max_element(vec) - vec.begin())
#define mini(vec) (rng::min_element(vec) - vec.begin())
#define some rng::any_of
#define all rng::all_of
#define none rng::none_of
#define iall(x) (x).begin(), (x).end()
#define odd(x) ((x) & 1)
#define even(x) (!(odd(x)))
#define get_bit(i, x) (((x) & (1 << (i))) != 0)

#define adj(n) rng::views::adjacent<n>
#define rev rng::views::reverse
#define transform rng::views::transform
#define izip rng::views::enumerate
#define iota rng::views::iota
#define filterIdx(...) izip | filter(__VA_ARGS__) | transform(uni(b(a)))
#define pb push_back
#define next(container) _nextElem(container, #container)

#define uni(...) [&](auto a) { return (__VA_ARGS__); }
#define bi(...) [&](auto a, auto b) { return (__VA_ARGS__); }
#define poly(...) [&](__VA_ARGS__)

#define rep(i, len) for (int i = 0; i < len; i++)
#define rrep(i, len) for (int i = len - 1; i >= 0; i--)
#define citer(left, right) for (const auto& left : right)
#define iter(left, right) for (auto& left : right)

#pragma endregion

void solve() {
    int(n);
    str(s);
    int sum = 0;
    vi colors;
    iter(c, s) {
        if (c == '(')
            sum++;
        else
            sum--;
        if (sum > 0) {
            colors.pb(1);
        } else if (sum < 0) {
            colors.pb(2);
        } else {
            colors.pb(b(colors));
        }
    }
    if (sum != 0) {
        ret(-1);
    }
    out(len(si(iall(colors))));
    if (all(colors, uni(a == 2)))
        out(colors | transform(uni(1)));
    else
        out(colors);
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
};