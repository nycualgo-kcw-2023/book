/**
 * Time Complexity: O(n^2)
**/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    
    vector<int> a(n), b(n);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = max({
                dp[i][j-1],
                dp[i-1][j],
                dp[i-1][j-1] + (a[i-1] != b[j-1])
            });
        }
    }
    
    vector<pair<int, int>> ans;
    {
        int nx = n, ny = n;
        while (nx and ny) {
                 if (dp[nx][ny] == dp[nx][ny-1]) --ny;
            else if (dp[nx][ny] == dp[nx-1][ny]) --nx;
            else ans.emplace_back(a[--nx], b[--ny]);
        }
        reverse(begin(ans), end(ans));
    }
    
    int m = dp[n][n];
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
