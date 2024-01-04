/**
 * Time Complexity: O(n^3)
**/

#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int INF = 1'000'000'000 + 5;
const i64 mod = 1'000'000'007;

vector<i64> solve_dp(int N, vector<i64> A) {
    vector<i64> dp(N+2, 0);
    dp[0] = 1;
    for (int i = 1; i <= N+1; ++i) {
        for (int j = 0; j < i; ++j) {
            if (A[j] > A[i]) continue;
            bool valid = true;
            for (int k = j+1; k <= i-1; ++k) {
                if (A[j] <= A[k] and A[k] <= A[i]) valid = false;
            }
            if (valid) dp[i] = (dp[i] + dp[j]) % mod;
        }
    }
    return dp;
}

void solve() {
    int N; cin >> N;
    
    vector<i64> A(N+2), nA(N+2);
    for (int i = 1; i <= N; ++i) cin >> A[i], nA[N+1-i] = INF - A[i];
    A[0] = nA[0] = 0, A[N+1] = nA[N+1] = INF;
    
    vector<i64> dp = solve_dp(N, A);
    vector<i64> ndp = solve_dp(N, nA);
    reverse(begin(ndp), end(ndp));
    
    i64 cnt = dp[N+1], sum = 0;
    for (int i = 1; i <= N; ++i) sum = (sum + dp[i] * ndp[i] % mod * A[i]) % mod;
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
