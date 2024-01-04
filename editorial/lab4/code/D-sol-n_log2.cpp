/**
 * Time Complexity: O(n log^2 n)
**/

#include <bits/stdc++.h>
using namespace std;

#define int int64_t

const int INF = 1'000'000'000 + 5;
const int mod = 1'000'000'007;

struct ID {
    int a, i, sum;
    ID (int _a, int _i, int _sum) :
        a(_a), i(_i), sum(_sum) {}
    bool operator < (const ID &rhs) { return a > rhs.a; }
};

vector<int> solve_dp(int N, vector<int> A) {
    
    vector<pair<int, int>> disc;
    for (int i = 0; i <= N+1; ++i) disc.emplace_back(A[i], i);
    sort(begin(disc), end(disc));
    
    vector<int> _id(N+2);
    for (int i = 0; i <= N+1; ++i) {
        A[i] = lower_bound(begin(disc), end(disc), pair{A[i], i}) - begin(disc);
        _id[A[i]] = i;
    }
    
    vector<int> dp(N+2, 0); dp[0] = 1;
    
    function<void(vector<int>, int, int)> recur = [&](vector<int> id, int L, int R) {
        if (L == R) return;
        
        int M = (L + R) >> 1;
        vector<int> id_L, id_R;
        for (int i : id) (i <= M ? id_L : id_R).emplace_back(i);
        recur(id_L, L, M);
        
        deque<ID> stk_L; /// (a[i], i, prefix_sum)
        deque<int> stk_R; /// (i)
        for (int i : id) {
            if (i <= M) {
                /// maintain stk with increasing a[i] and decreasing i ([0] is smallest) ///
                while (stk_L.size() and i > stk_L[0].i) stk_L.pop_front();
                stk_L.emplace_front(A[i], i, (stk_L.size() ? stk_L[0].sum : 0) + dp[i]);
            }
            else {
                /// maintain stk with increasing a[i] and increasing i ([0] is largest) ///
                while (stk_R.size() and i < stk_R[0]) stk_R.pop_front();
                /// query stk_L range sum (back, stk_R[0]) ///
                if (stk_L.size()) {
                    auto it = lower_bound(begin(stk_L), end(stk_L), ID{(stk_R.size() ? A[stk_R[0]] : -1), 0, 0});
                    // while (it != begin(stk_L)) {
                    //     it = prev(it);
                    //     dp[i] = (dp[i] + dp[it->i]) % mod;
                    //     debug(i, it->i);
                    // }
                    int cnt = (stk_L[0].sum - (it != end(stk_L) ? it->sum : 0)) % mod;
                    dp[i] = (dp[i] + cnt) % mod;
                }
                stk_R.emplace_front(i);
            }
        }
        
        recur(id_R, M+1, R);
    };
    recur(_id, 0, N+1);
    
    return dp;
}

void solve() {
    int N; cin >> N;
    
    vector<int> A(N+2), nA(N+2);
    for (int i = 1; i <= N; ++i) cin >> A[i], nA[N+1-i] = INF - A[i];
    A[0] = nA[0] = 0, A[N+1] = nA[N+1] = INF;
    
    vector<int> dp = solve_dp(N, A);
    vector<int> ndp = solve_dp(N, nA);
    reverse(begin(ndp), end(ndp));
    
    int cnt = dp[N+1], sum = 0;
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
