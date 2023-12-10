#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    int N, M; cin >> N >> M;
    
    vector<int64> U(N), V(M), A(N*M);
    for (int64 &x : U) cin >> x;
    for (int64 &x : V) cin >> x;
    for (int64 &x : A) cin >> x;
    sort(begin(A), end(A));
    
    /// ans = sum_i sum_j u[i] * A[i][j] * v[j] ///
    
    vector<int> id(N*M), id_inv(N*M);
    iota(begin(id), end(id), 0);
    sort(begin(id), end(id), [&](int x, int y) {
        int rx = x / M, cx = x % M;
        int ry = y / M, cy = y % M;
        return U[rx] * V[cx] < U[ry] * V[cy];
    });
    for (int i = 0; i < N*M; ++i) id_inv[id[i]] = i;
    
    stringstream sout;
    int64 ans = 0;
    for (int i = 0; i < N; ++i) sout << U[i] << " \n"[i == N-1];
    for (int j = 0; j < M; ++j) sout << V[j] << " \n"[j == M-1];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            sout << A[id_inv[M*i + j]] << " \n"[j == M-1];
            ans += U[i] * A[id_inv[M*i + j]] * V[j];
        }
    }
    
    cout << ans << "\n";
    cout << sout.str();
    
    return 0;
}
