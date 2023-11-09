#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    int N, K; cin >> N >> K;
    
    vector<int> A(N);
    for (int &x : A) cin >> x;
    
    int64_t ans = (K == 0 ? N : 0);
    
    function<void(int, int)> recur = [&](int L, int R) {
        if (L == R) return;
        int M = (L + R) >> 1;
        recur(L, M), recur(M+1, R);
        
        static vector<int> mn(N), mx(N);
        static map<int, int> cnt1, cnt2;
        mn[M] = mx[M] = A[M];
        for (int i = M-1; i >= L; --i) mn[i] = min(mn[i+1], A[i]), mx[i] = max(mx[i+1], A[i]);
        mn[M+1] = mx[M+1] = A[M+1];
        for (int i = M+2; i <= R; ++i) mn[i] = min(mn[i-1], A[i]), mx[i] = max(mx[i-1], A[i]);
        
        for (int l = M, r1 = M, r2 = M; l >= L; --l) {
            /// r1: last pos which mn[r1] and mx[r1] is between mn[l] and mx[l] ///
            /// r1: [max - min - r + l = k] ==> [r = l - k + max - min] ///
            while (r1 < R and mn[r1+1] > mn[l] and mx[r1+1] < mx[l]) {
                ++r1;
                ++cnt1[r1];
                --cnt2[r1 + mn[r1]];
            }
            /// r2: last pos which mx[r2] is below mx[l] ///
            /// r2: [max - min - r + l = k] ==> [r + min = l - k + max] ///
            while (r2 < R and mx[r2+1] < mx[l]) {
                ++r2;
                ++cnt2[r2 + mn[r2]];
            }
            ans += cnt1[l - K + mx[l] - mn[l]];
            ans += cnt2[l - K + mx[l]];
        }
        cnt1.clear(), cnt2.clear();
        
        for (int l1 = M+1, l2 = M+1, r = M+1; r <= R; ++r) {
            /// l1: first pos which mn[l1] and mx[l1] is between mn[r] and mx[r] ///
            /// l1: [max - min - r + l = k] ==> [l = r + k + min - max] ///
            while (l1 > L and mn[l1-1] > mn[r] and mx[l1-1] < mx[r]) {
                --l1;
                ++cnt1[l1];
                --cnt2[l1 - mn[l1]];
            }
            /// l2: first pos which mx[l2] is below mx[r] ///
            /// l2: [max - min - r + l = k] ==> [l - min = r + k - max] ///
            while (l2 > L and mx[l2-1] < mx[r]) {
                --l2;
                ++cnt2[l2 - mn[l2]];
            }
            ans += cnt1[r + K + mn[r] - mx[r]];
            ans += cnt2[r + K - mx[r]];
        }
        cnt1.clear(), cnt2.clear();
    };
    
    recur(0, N-1);
    
    cout << ans << "\n";
    
    return 0;
}
