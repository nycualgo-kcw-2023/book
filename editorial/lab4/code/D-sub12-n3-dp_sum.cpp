/**
 * Time Complexity: O(n^3)
**/

#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const i64 mod = 1'000'000'007;

void solve() {
    int N; cin >> N;
    
    vector<i64> A(N+2), nA(N+2);
    for (int i = 1; i <= N; ++i) cin >> A[i], nA[N+1-i] = mod - A[i];
    A[0] = 0, A[N+1] = mod;
    
    vector<pair<i64, i64>> dp(N+2, {0, 0});
    dp[0] = {1, 0};
    for (int i = 1; i <= N+1; ++i) {
        for (int j = 0; j < i; ++j) {
            if (A[j] > A[i]) continue;
            bool valid = true;
            for (int k = j+1; k <= i-1; ++k) {
                if (A[j] <= A[k] and A[k] <= A[i]) valid = false;
            }
            if (valid) {
                dp[i].first = (dp[i].first + dp[j].first) % mod;
                dp[i].second = (dp[i].second + dp[j].second + dp[j].first * A[i]) % mod;
            }
        }
    }
    
    i64 cnt = dp[N+1].first, sum = dp[N+1].second;
    cout << cnt << " " << sum << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    int t = 1; cin >> t;
    for (int _ = 1; _ <= t; ++_) {
        solve();
    }
    
    return 0;
}
