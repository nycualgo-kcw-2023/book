#include <bits/stdc++.h>
using namespace std;

int maxnc = 1'000'000 * 1'000 + 5;

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    int N; cin >> N;
    
    vector<int> a(N+1), w(N+1);
    for (int i = 1; i <= N; ++i) cin >> a[i];
    for (int i = 1; i <= N; ++i) cin >> w[i];
    
    auto check = [&](int pass) -> int64_t {
        int64_t cost = 0;
        for (int i = 1, sum = a[1] + pass; i <= N-1; sum += a[++i]) {
            cost += 1LL * w[i] * abs(sum);
        }
        return cost;
    };
    
    int lo = -maxnc, hi = maxnc, m1, m2;
    while (lo < hi) {
        m1 = lo + (hi - lo) / 3;
        m2 = hi - (hi - lo) / 3;
        if (check(m1) < check(m2)) hi = m2 - 1;
        else                       lo = m1 + 1;
    }
    cout << check(lo) << "\n";
    
    return 0;
}
