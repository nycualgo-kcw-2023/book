#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    // Input...

    vector<ll> A_flat(n * m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; j++) {
            A_flat[i * m + j] = A[i][j];
        }
    }

    sort(v.begin(), v.end());
    sort(A_flat.begin(), A_flat.end());

    ll max_val = 0;
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; ++i) {
            A[i][j] = A_flat[j * n + i];
            max_val += A[i][j] * v[j];
        }
    }

    // Output...
}
