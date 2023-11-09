#include <bits/stdc++.h>
using namespace std;

template <typename T, typename U> bool chmin(T &lhs, U rhs) {return lhs > rhs ? lhs = rhs, 1 : 0;}
template <typename T, typename U> bool chmax(T &lhs, U rhs) {return lhs < rhs ? lhs = rhs, 1 : 0;}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    int N, K; cin >> N >> K;
    
    vector<int> A(N);
    for (int &x : A) cin >> x, --x;
    
    int64_t ans = 0;
    for (int l = 0; l < N; ++l) {
        for (int r = l, mn = A[l], mx = A[l]; r < N; ++r) {
            chmin(mn, A[r]), chmax(mx, A[r]);
            if ((mx - mn) - (r - l) == K) ++ans;
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}
