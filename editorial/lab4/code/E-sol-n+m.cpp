/**
 * Time Complexity: O(n+m)
**/

#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX >> 1;

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    int n, m; cin >> n >> m;
    
    vector<int> l(n);
    for (int &x : l) cin >> x;
    
    vector<vector<pair<int, int>>> adj(2*n+1);
    vector<int> deg_i(2*n+1, 0), vis(2*n+1, 0);
    for (int i = 0; i < 2*n; ++i) {
        if (l[i>>1] == 0) adj[2*n].emplace_back(i, 0),    ++deg_i[i];
        else              adj[2*n].emplace_back(i, -INF), ++deg_i[i];
    }
    for (int i = 0; i < m; ++i) {
        int u, v, w; char c; cin >> u >> v >> c >> w, --u, --v;
        if (c == 'B') adj[u<<1].emplace_back(v<<1|1, w), ++deg_i[v<<1|1];
        if (c == 'W') adj[u<<1|1].emplace_back(v<<1, w), ++deg_i[v<<1];
    }
    
    vector<int> ans(n, 0);
    vector<int> dp(2*n+1, 0);
    function<void(int)> dag_dp = [&](int now) {
        for (auto [x, star] : adj[now]) {
            dp[x] = max(dp[x], dp[now] + star);
            if (++vis[x] == deg_i[x]) {
                ans[x>>1] = max(ans[x>>1], dp[x]);
                if (dp[x] < l[x>>1]) dp[x] = -INF;
                dag_dp(x);
            }
        }
    };
    dag_dp(2*n);
    
    for (int i = 0; i < n; ++i) cout << ans[i] << " \n"[i == n-1];
    
    return 0;
}
