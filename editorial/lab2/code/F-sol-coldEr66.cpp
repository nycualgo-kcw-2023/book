#ifndef Yamada
#define Yamada
#include Yamada __FILE__ Yamada

const int maxn = 1e6+5;
const int INF = INT_MAX;

int A[maxn];
vector<int> suf_mn(maxn+5, INF), suf_mx(maxn+5, -1);
vector<int> pre_mn(maxn+5, INF), pre_mx(maxn+5, -1);
vector<int> cnt(maxn << 1, 0), cnt1(maxn << 1, 0);

int gogo(int L, int R, int K) {
    if (L == R-1) return (K == 0);
    int M = (L + R) >> 1;

    for (int i = M - 1; i >= L; --i) {
        suf_mn[i] = min(suf_mn[i+1], A[i]);
        suf_mx[i] = max(suf_mx[i+1], A[i]);
    }
    for (int i = M; i < R; ++i) {
        pre_mn[i] = min(pre_mn[i-1], A[i]);
        pre_mx[i] = max(pre_mx[i-1], A[i]);
    }

    int ret = 0;
    int R_min = M, R_max = M;
    int mx = -1, mn = INF;
    for (int i = M - 1; i >= L; --i) {
        chmax(mx, A[i]), chmin(mn, A[i]);
        while (R_max < R && pre_mx[R_max] <= mx) {
            cnt[pre_mn[R_max] + R_max]++;
            R_max++;
        }
        while (R_min < R_max && pre_mn[R_min] >= mn) {
            cnt[pre_mn[R_min] + R_min]--;
            R_min++;
        }
        int R_target = mx - mn + i - K;
        ret += (M <= R_target && R_target < R_min);
        if (mx + i - K >= 0) ret += max(int(0), cnt[mx + i - K]);
    }
    while (R_min < R_max) cnt[pre_mn[R_min] + R_min]--, R_min++;

    int L_min = M-1, L_max = M-1;
    mx = -1, mn = INF;
    for (int i = M; i < R; ++i) {
        chmax(mx, A[i]), chmin(mn, A[i]);
        while (L_max >= L && suf_mx[L_max] < mx) {
            cnt1[suf_mn[L_max] - L_max + maxn]++;
            L_max--;
        }
        while (L_min > L_max && suf_mn[L_min] >= mn) {
            cnt1[suf_mn[L_min] - L_min + maxn]--;
            L_min--;
        }
        int tg = mn - mx + i + K;
        ret += (L_min < tg && tg < M);
        if (mx - i - K + maxn >= 0) ret += max(int(0), cnt1[mx - i - K + maxn]);
    }
    while (L_min > L_max) cnt1[suf_mn[L_min] - L_min + maxn]--, L_min--;

    for (int i = M - 1; i >= L; --i) {
        suf_mn[i] = INF, suf_mx[i] = -1;
    }
    for (int i = M; i < R; ++i) {
        pre_mn[i] = INF, pre_mx[i] = -1;
    }
    return ret + gogo(L, M, K) + gogo(M, R, K);
}

void solve() {
    int N, K; cin >> N >> K;
    for (int i = 1; i <= N; ++i) cin >> A[i];
    cout << gogo(1, N+1, K) << '\n';
}

signed main() {
    IOS();
    int t = 1; // cin >> t;
    for (int i=1;i<=t;++i) solve();
    return 0;
}

#else

#ifdef cold66
#define _GLIBCXX_DEBUG 1
#endif
#pragma GCC optimize ("Ofast", "unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int int64_t
// #define double __float80
using pii = pair<int, int>;
template <typename T> using MaxHeap = priority_queue<T>;
template <typename T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;

#define SZ(a) ((int)(a).size())
#define ALL(a) begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)
#define ee emplace
#define eb emplace_back
#define ef emplace_front
#define pb pop_back
#define pf pop_front
// #define X first
// #define Y second

template <size_t D, typename T> struct Vec : vector<Vec<D-1, T>> {
    template <typename... U> Vec(int n = 0, U ... _u) : vector<Vec<D-1, T>>(n, Vec<D-1, T>(_u...)) {}
};
template <typename T> struct Vec<1, T> : vector<T> {
    Vec(int n = 0, const T& val = T()) : vector<T>(n, val) {}
};

#ifdef local
#define IOS() void()
#define debug(...) \
    fprintf(stderr, "\e[3;93m"), \
    fprintf(stderr, "At [%s], line %d: (%s) = ", __FUNCTION__, __LINE__, #__VA_ARGS__), \
    _do(__VA_ARGS__), \
    fprintf(stderr, "\e[3;0m")
template <typename T> void _do(T &&_t) {cerr << _t << endl;}
template <typename T, typename ...U> void _do(T &&_t, U &&..._u) {cerr << _t << ", ", _do(_u...);}
#else
#define IOS() ios_base::sync_with_stdio(0); cin.tie(0)
#define debug(...) void()
#define endl '\n'
#endif

template <typename U, typename V> bool chmin(U &u, V v) {return u > v ? u = v, 1 : 0;}
template <typename U, typename V> bool chmax(U &u, V v) {return u < v ? u = v, 1 : 0;}

#endif
