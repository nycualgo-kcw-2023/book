/**
 * Time Complexity: O(4^n)
**/

#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX >> 1;

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    int n; cin >> n;
    unsigned U = (1 << n) - 1;
    
    vector<vector<int>> c(n, vector<int>(n, 0));
    for (auto &vec : c) for (int &x : vec) cin >> x;
    
    vector<int> cost(U+1, 0);
    for (unsigned S = 0; S <= U; ++S) {
        if (popcount(S) == 1) cost[S] = INF;
        else {
            for (int i = 0; i < n; ++i) {
                if (~S >> i & 1) continue;
                for (int j = i+1; j < n; ++j) {
                    if (~S >> j & 1) continue;
                    cost[S] += c[i][j];
                }
            }
        }
    }
    
    vector<int> dp(U+1, INF), fr(U+1, 0);
    dp[0] = 0;
    for (unsigned S = 0; S <= U; ++S) {
        for (unsigned T = S+1; T <= U; ++T) {
            if ((S & T) == 0 and dp[S | T] > dp[S] + cost[T]) {
                dp[S | T] = dp[S] + cost[T];
                fr[S | T] = T;
            }
        }
    }
    
    vector<int> ans(n, 0);
    int tok = 0;
    unsigned now = U;
    while (now) {
        ++tok;
        
        unsigned ids = fr[now];
        while (ids) ans[__lg(ids & -ids)] = tok, ids -= ids & -ids;
        
        now ^= fr[now];
    }
    
    cout << dp.back() << "\n";
    for (int i = 0; i < n; ++i) cout << ans[i] << " \n"[i == n-1];
    
    return 0;
}
