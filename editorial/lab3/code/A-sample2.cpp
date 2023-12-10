#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

const int64 INF = 1E16;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    int N, Q; cin >> N >> Q;
    
    vector<int64> V(N), pre;
    for (int64 &x : V) cin >> x;
    V.emplace_back(INF);
    sort(begin(V), end(V));
    partial_sum(begin(V), end(V), back_inserter(pre));
    
    auto sum = [&](int L, int R) -> int64 { return pre[R] - pre[L] + V[L]; };
    
    for (int q = 1; q <= Q; ++q) {
        int64 X, Y; cin >> X >> Y;
        
        vector<pair<int, int>> alive;
        int cnt = 0, lst = 0;
        while (X < Y) {
            int pos = upper_bound(begin(V), end(V), X) - begin(V);
            int64 goal = min(V[pos], Y);
            alive.emplace_back(lst, pos - 1);
            
            while (alive.size() and X + sum(alive.back().first, alive.back().second) < goal) {
                X += sum(alive.back().first, alive.back().second);
                cnt += alive.back().second - alive.back().first + 1;
                alive.pop_back();
            }
            
            if (alive.empty()) { cnt = -1; break; }
            
            auto [L, R] = alive.back();
            int lo = L, hi = R, mi;
            while (lo < hi) {
                mi = (lo + hi + 1) >> 1;
                if (X + sum(mi, R) < goal) hi = mi - 1;
                else                       lo = mi;
            }
            
            X += sum(lo, R);
            cnt += R - lo + 1;
            alive.back().second = lo - 1;
            if (alive.back().first > alive.back().second) alive.pop_back();
            
            lst = pos;
        }
        cout << cnt << "\n";
    }
    
    return 0;
}