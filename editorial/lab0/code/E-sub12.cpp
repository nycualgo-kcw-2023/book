#include <bits/stdc++.h>
using namespace std;

struct Group { int size, mask; };

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    int Q; cin >> Q;
    
    deque<Group> que;
    for (int q = 1; q <= Q; ++q) {
        int op; cin >> op;
        if (op == 1) {
            int k; cin >> k;
            for (Group &g : que) g.mask += k;
        }
        else if (op == 2) {
            int x; cin >> x;
            while (!que.empty() and x >= que[0].size) {
                x -= que[0].size;
                que.pop_front();
            }
            if (x) que[0].size -= x;
        }
        else if (op == 3) {
            int y; cin >> y;
            que.push_back(Group{.size = y, .mask = 0});
        }
        int max_mask = 0;
        for (Group g : que) max_mask = max(max_mask, g.mask);
        cout << max_mask << "\n";
    }
    
    return 0;
}
