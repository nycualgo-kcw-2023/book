/**
 * Time Complexity: O(n log n + m log m)
**/

#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    int N, M, mod; cin >> N >> M >> mod;
    
    vector<tuple<int, int, int>> edges(M);
    for (auto &[s, u, v] : edges) cin >> u >> v, s = v - u;
    sort(begin(edges), end(edges));
    
    vector<int> dp[2];
    dp[0].assign(N+1, 1), dp[0][0] = 0;
    dp[1].assign(N+1, 0);
    
    auto modadd = [&](int x, int y) -> int { return (x + y >= mod ? x + y - mod : x + y); };
    
    for (int step = 1, tok1 = 0, tok2 = 0; step <= N; ++step) {
        
        for (int i = step; i <= N; i += step) dp[1][i] = modadd((i+step <= N ? dp[0][i+step] : 0), dp[0][i-step]);
        while (tok1 < M and get<0>(edges[tok1]) == step) {
            auto [s, u, v] = edges[tok1++];
            dp[1][v] = modadd(dp[1][v], dp[0][u]);
            dp[1][u] = modadd(dp[1][u], dp[0][v]);
        }
        
        for (int i = step; i <= N; i += step) dp[0][i] = modadd(dp[0][i], dp[1][i]), dp[1][i] = 0;
        while (tok2 < tok1) {
            auto [s, u, v] = edges[tok2++];
            dp[0][v] = modadd(dp[0][v], dp[1][v]), dp[1][v] = 0;
            dp[0][u] = modadd(dp[0][u], dp[1][u]), dp[1][u] = 0;
        }
        
    }
    
    int ans = mod - N;
    for (int i = 1; i <= N; ++i) ans = modadd(ans, dp[0][i]);
    cout << ans << "\n";
    
    return 0;
}
