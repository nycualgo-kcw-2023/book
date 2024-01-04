/**
 * Time Complexity: O(2^n n^2)
**/

#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX >> 1;

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    int n; cin >> n;
    int U = (1 << n) - 1;
    
    vector<vector<int>> c(n, vector<int>(n));
    for (auto &vec : c) for (int &x : vec) cin >> x;
    
    vector<vector<int>> cost2(n, vector<int>(n));
    vector<vector<vector<int>>> cost3(n, vector<vector<int>>(n, vector<int>(n)));
    for (int i = 0; i < n; ++i) for (int j = i+1; j < n; ++j) cost2[i][j] = c[i][j];
    for (int i = 0; i < n; ++i) for (int j = i+1; j < n; ++j) for (int k = j+1; k < n; ++k) cost3[i][j][k] = c[i][j] + c[i][k] + c[j][k];
    
    vector<int> dp(U+1, INF), fr(U+1, -1); dp[0] = 0;
    for (int mask = 1; mask <= U; ++mask) {
        int i = __lg(mask & -mask);
        for (int j = i+1; j < n; ++j) {
            if (~mask >> j & 1) continue;
            if (dp[mask] > dp[mask^(1<<i)^(1<<j)] + cost2[i][j]) {
                dp[mask] = dp[mask^(1<<i)^(1<<j)] + cost2[i][j];
                fr[mask] = (1<<i) | (1<<j);
            }
            for (int k = j+1; k < n; ++k) {
                if (~mask >> k & 1) continue;
                if (dp[mask] > dp[mask^(1<<i)^(1<<j)^(1<<k)] + cost3[i][j][k]) {
                    dp[mask] = dp[mask^(1<<i)^(1<<j)^(1<<k)] + cost3[i][j][k];
                    fr[mask] = (1<<i) | (1<<j) | (1<<k);
                }
            }
        }
    }
    
    vector<int> ans(n, 0);
    int now = U, tok = 0;
    while (now) {
        ++tok;
        
        int ids = fr[now];
        while (ids) ans[__lg(ids & -ids)] = tok, ids -= ids & -ids;
        
        now ^= fr[now];
    }
    
    cout << dp.back() << "\n";
    for (int i = 0; i < n; ++i) cout << ans[i] << " \n"[i == n-1];
    
    return 0;
}
