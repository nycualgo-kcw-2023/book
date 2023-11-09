#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using pii = pair<i64, i64>;

pii mul(pii a, pii b, i64 k, i64 p) {
    return {
        (a.first * b.first % p * k + a.first * b.second + a.second * b.first + a.second * b.second / k) % p,
        a.second * b.second % k
    };
}

pii fpow(pii base, i64 exp, i64 k, i64 p, pii ans = {0, 1}) {
    while (exp) {
        if (exp & 1) ans = mul(ans, base, k, p);
        exp >>= 1, base = mul(base, base, k, p);
    }
    return ans;
}

void solve() {
    i64 x, y, k, p; cin >> x >> y >> k >> p;
    
    cout << fpow({x/k, x%k}, y, k, p).first % p << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    int t; cin >> t;
    while (t--) solve();
    
    return 0;
}
