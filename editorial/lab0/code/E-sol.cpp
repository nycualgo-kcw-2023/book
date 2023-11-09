#include <bits/stdc++.h>
using namespace std;

struct Group { int size; int64_t mask_diff; };

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    int Q; cin >> Q;
    
    deque<Group> que;
    for (int q = 1; q <= Q; ++q) {
        int op; cin >> op;
        if (op == 1) {
            int k; cin >> k;
            que[0].mask_diff += k;
            que.push_back(Group{.size = 0, .mask_diff = -k});
        }
        else if (op == 2) {
            int x; cin >> x;
            while (!que.empty() and x >= que[0].size) {
                x -= que[0].size;
                if (que.size() >= 2) que[1].mask_diff += que[0].mask_diff;
                que.pop_front();
            }
            if (x) que[0].size -= x;
        }
        else if (op == 3) {
            int y; cin >> y;
            que.push_back(Group{.size = y, .mask_diff = 0});
        }
        cout << (que.empty() ? 0 : que[0].mask_diff) << "\n";
    }
    
    return 0;
}
