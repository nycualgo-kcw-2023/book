/**
 * Time Complexity: O(n^1.5)
 * - The minimum answer is n - floor(sqrt(n)).
**/

#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX >> 1;

void solve() {
    int n; cin >> n;
    int sqn = int(ceil(sqrtl(n))) + 5;
    
    vector<int> a(n), b(n);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    
    vector<vector<int>> dp(n+1, vector<int>(sqn+1, INF));
    for (int j = 0; j <= sqn; ++j) dp[0][j] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = dp[i-1][0] + 1 + (dp[i-1][0] < n and a[i-1] == b[dp[i-1][0]]);
        for (int j = 1; j <= sqn; ++j) {
            dp[i][j] = min(
                dp[i-1][j-1],
                dp[i-1][j] + 1 + (dp[i-1][j] < n and a[i-1] == b[dp[i-1][j]])
            );
        }
    }
    
    for (int j = 0; j <= sqn; ++j) {
        if (dp[n][j] > n) continue;
        
        int nx = n, ny = j;
        vector<pair<int, int>> ans;
        while (nx) {
            if (ny and dp[nx][ny] == dp[nx-1][ny-1]) --nx, --ny;
            else ans.emplace_back(a[nx-1], b[dp[nx][ny]-1]), --nx;
        }
        reverse(begin(ans), end(ans));
        
        cout << n - j << "\n";
        for (int i = 0; i < n-j; ++i) cout << ans[i].first  << " \n"[i == n-j-1];
        for (int i = 0; i < n-j; ++i) cout << ans[i].second << " \n"[i == n-j-1];
        
        break;
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    int t = 1; cin >> t;
    for (int _ = 1; _ <= t; ++_) {
        solve();
    }
    
    return 0;
}
