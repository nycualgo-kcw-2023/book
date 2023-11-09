#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    int n, q; cin >> n >> q;
    
    vector<int> inv(n);
    for (int i = 0, b_i; i < n; ++i) cin >> b_i, inv[--b_i] = i;
    
    for (int i = 1; i <= q; ++i) {
        int l, r; cin >> l >> r, --l, --r;
        sort(begin(inv) + l, begin(inv) + r + 1);
        if (is_sorted(begin(inv), end(inv))) {
            cout << i << "\n";
            return 0;
        }
    }
    
    cout << -1 << "\n";
    
    return 0;
}
