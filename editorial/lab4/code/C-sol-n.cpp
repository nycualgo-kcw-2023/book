/**
 * Time Complexity: O(n)
**/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    
    vector<int> a(n+1), b(n+1), inv(n+1), bar(n+1);
    for (int i = 1; i <= n; ++i) cin >> a[i], inv[a[i]] = i;
    for (int i = 1; i <= n; ++i) cin >> b[i], bar[inv[b[i]]] = i;
    
    vector<pair<int, int>> dp(2*n+1); /// [-n, n]
    vector<pair<int, int>> fr(n+2, {0, 0}); /// [2, n+1]
    for (int i = 0; i <= n; ++i) dp[i - 0 + n] = {0, i + 0};
    for (int j = 1; j <= n; ++j) dp[0 - j + n] = {0, 0 + j};
    
    for (int i = 2; i <= n+1; ++i) {
        int j = bar[i-1] + 1;
        auto [val_u, lst_u] = dp[(i-1) - j + n]; val_u += ((i-1) + j - lst_u) / 2;
        auto [val_l, lst_l] = dp[i - (j-1) + n]; val_l += (i + (j-1) - lst_l) / 2;
        if (val_u >= val_l) dp[i - j + n] = {val_u, i + j}, fr[i] = {-1, 0};
        else                dp[i - j + n] = {val_l, i + j}, fr[i] = {0, -1};
    }
    
    auto [val, lst] = dp[n - n + n]; val += (n + n - lst) / 2;
    int m = val;
    vector<pair<int, int>> ans;
    
    {
        int i = n+1, j = n+1;
        while (i > 1 and j > 1) {
            if (bar[i-1] == j-1) {
                auto [di, dj] = fr[i];
                i += di, j += dj;
            }
            else {
                --i, --j;
                if (i and j) ans.emplace_back(a[i], b[j]);
            }
        }
        reverse(begin(ans), end(ans));
    }
    
    cout << m << "\n";
    for (int i = 0; i < m; ++i) cout << ans[i].first  << " \n"[i == m-1];
    for (int i = 0; i < m; ++i) cout << ans[i].second << " \n"[i == m-1];
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    int t = 1; cin >> t;
    for (int _ = 1; _ <= t; ++_) {
        solve();
    }
    
    return 0;
}
