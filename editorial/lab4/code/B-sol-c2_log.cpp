/**
 * Time Complexity: O(C^2 log V)
**/

#include <bits/stdc++.h>
using namespace std;

#define int int64_t

const int INF = LLONG_MAX >> 1;
const int maxc = 1200 + 5;

struct State {
    
    vector<int> dp;
    
    State () { dp.assign(2 * maxc + 1, 0); }
    
    int& operator [] (int x)       { return dp[x + maxc]; }
    int  operator [] (int x) const { return dp[x + maxc]; }
    
    State operator * (const State &rhs) const {
        const State &lhs = *this;
        State res;
        for (int i = -maxc; i <= maxc; ++i) {
            for (int j = max(-maxc, -maxc-i); j <= min(maxc, maxc-i); ++j) {
                res[i+j] = max(res[i+j], lhs[i] + rhs[j]);
            }
        }
        return res;
    }
    
};

void solve() {
    int n, V; cin >> n >> V;
    
    vector<int> c(n), v(n);
    for (int &x : c) cin >> x;
    for (int &x : v) cin >> x;
    
    vector<int> best(maxc, 0);
    for (int i = 0; i < n; ++i) best[c[i]] = max(best[c[i]], v[i]);
    
    State base, ans;
    for (int i = 0; i <= 2*maxc; ++i) {
        for (int j = 1; j <= min(i, maxc-1); ++j) {
            base.dp[i] = max(base.dp[i], base.dp[i-j] + best[j]);
        }
    }
    for (int i = -maxc; i <= maxc; ++i) ans[i] = (i < 0 ? -INF : base[i - maxc]);
    
    // assert(base.dp == (ans * base).dp);
    
    int exp = V / maxc;
    while (exp) {
        if (exp & 1) ans = ans * base;
        exp >>= 1, base = base * base;
    }
    
    cout << ans[V % maxc] << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    int t = 1; cin >> t;
    for (int _ = 1; _ <= t; ++_) {
        solve();
    }
    
    return 0;
}
