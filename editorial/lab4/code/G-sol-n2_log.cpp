/**
 * Time Complexity: seems like O(n^2 log n) with const. opt.
**/

#include <bits/stdc++.h>
using namespace std;

#define int int64_t

const int INF = LLONG_MAX >> 2;

struct State {
    
    int base;
    deque<int> v;
    
    State (int b = INF, int sz = 1) : base(b), v(sz, INF) {}
    State (int b, initializer_list<int> vec) : base(b), v(vec) {}
    
    int get_min_cost() {
        int ans = INF;
        for (int i = 0, b = base; i < int(v.size()); ++i, b += 3) {
            if (b >= 0) ans = min(ans, v[i]);
        }
        return ans;
    }
    
    State operator + (const State &rhs) {
        const State &lhs = *this;
        State now(lhs.base + rhs.base, int(lhs.v.size()) + int(rhs.v.size()) - 1);
        for (int i = 0; i < int(lhs.v.size()); ++i) {
            for (int j = 0; j < int(rhs.v.size()); ++j) {
                now.v[i + j] = min(now.v[i + j], lhs.v[i] + rhs.v[j]);
            }
        }
        return now;
    }
    
    State operator + (int cost) {
        State now = *this;
        for (int &x : now.v) x += cost;
        return now;
    }
    
    friend void chmin(State &lhs, const State &rhs) {
        /// extend lhs.v to [min(lhs.base, rhs.base), max(lhs.base + SZ(lhs.v), rhs.base + SZ(rhs.v))) ///
        if (lhs.base == INF) { lhs = rhs; return; }
        while (lhs.base > rhs.base) lhs.v.emplace_front(INF), lhs.base -= 3;
        while (lhs.base + 3*int(lhs.v.size()) < rhs.base + 3*int(rhs.v.size())) lhs.v.emplace_back(INF);
        for (int r = 0, l = (rhs.base - lhs.base) / 3; r < int(rhs.v.size()); ++r, ++l) {
            lhs.v[l] = min(lhs.v[l], rhs.v[r]);
        }
    }
    
};

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    int n, C; cin >> n >> C;
    
    vector<int> c(3*n);
    for (int i = 1; i <= 3*n-1; ++i) cin >> c[i];
    
    map<pair<int, int>, State> dp;
    
    function<void(int, int)> recur = [&](int L, int R) {
        if (dp.count({L, R})) return;
        if (R - L == 1) { dp[{L, R}] = State( 1, {0}); return; }
        if (R - L == 2) { dp[{L, R}] = State(-1, {0}); }
        if (R - L == 3) { dp[{L, R}] = State( 0, {0}); }
        
        int M = (L + R) >> 1;
        
        auto &now = dp[{L, R}];
        for (int m = max(L+1, M-2); m <= min(R-1, M+2); ++m) {
            int base_cost = c[m] + (R - L) * C;
            recur(L, m), recur(m, R);
            auto &dpL = dp[{L, m}], &dpR = dp[{m, R}];
            chmin(now, dpL + dpR + base_cost);
        }
    };
    
    recur(0, 3*n);
    
    int ans = dp[{0, 3*n}].get_min_cost();
    cout << ans << "\n";
    
    return 0;
}
