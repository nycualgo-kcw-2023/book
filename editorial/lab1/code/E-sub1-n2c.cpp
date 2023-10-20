#include <bits/stdc++.h>
using namespace std;

const int maxnc = 100 * 100 + 5;
const int maxw = 1000;

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
    
    int64_t ans = maxnc * maxw;
    for (int i = -maxnc; i <= maxnc; ++i) ans = min(ans, check(i));
    cout << ans << "\n";
    
    return 0;
}
