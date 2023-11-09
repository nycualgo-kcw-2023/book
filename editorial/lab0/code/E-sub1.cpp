#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    int Q; cin >> Q;
    
    deque<int> que;
    for (int q = 1; q <= Q; ++q) {
        int op; cin >> op;
        if (op == 1) {
            int k; cin >> k;
            for (int &mask : que) mask += k;
        }
        else if (op == 2) {
            int x; cin >> x;
            while (x--) que.pop_front();
        }
        else if (op == 3) {
            int y; cin >> y;
            while (y--) que.emplace_back(0);
        }
        int max_mask = 0;
        for (int mask : que) max_mask = max(max_mask, mask);
        cout << max_mask << "\n";
    }
    
    return 0;
}
