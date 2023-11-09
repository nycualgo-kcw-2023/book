#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using i128 = __int128;

i128 fpow(i128 base, i128 exp, i128 mod, i128 ans = 1) {
    while (exp) {
        if (exp & 1) ans = ans * base % mod;
        exp >>= 1, base = base * base % mod;
    }
    return ans;
}

void solve() {
    i64 x, y, k, p; cin >> x >> y >> k >> p;
    
    cout << i64(fpow(x, y, k*p) / k % p) << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    int t; cin >> t;
    while (t--) solve();
    
    return 0;
}
