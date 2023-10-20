#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    int N; cin >> N;
    
    vector<pair<int, int>> bw(N+1);
    int sum_w = 0;
    for (int i = 1; i <= N; ++i) cin >> bw[i].first, bw[i].first += bw[i-1].first;
    for (int i = 1; i <= N; ++i) cin >> bw[i].second, sum_w += bw[i].second;
    
    int lo = 1, hi = N, mi, pre = 0, tmp;
    while (lo < hi) {
        mi = (lo + hi) >> 1;
        nth_element(begin(bw) + lo, begin(bw) + mi, begin(bw) + hi + 1);
        tmp = pre;
        for (int i = lo; i <= mi; ++i) tmp += bw[i].second;
        if (2*tmp < sum_w) lo = mi + 1, pre = tmp;
        else               hi = mi;
    }
    
    auto check = [&](int pass) -> int64_t {
        int64_t cost = 0;
        for (int i = 1; i <= N; ++i) {
            cost += 1LL * abs(bw[i].first + pass) * bw[i].second;
        }
        return cost;
    };
    
    cout << check(-bw[lo].first) << "\n";
    
    return 0;
}
