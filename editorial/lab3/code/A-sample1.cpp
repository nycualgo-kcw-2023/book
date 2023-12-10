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
    
    for (int q = 1; q <= Q; ++q) {
        int64 X, Y; cin >> X >> Y;
        
        stack<int> alive;
        int cnt = 0;
        for (int i = 0; i <= N and X < Y; ++i) {
            while (alive.size() and X < min(V[i], Y)) X += alive.top(), alive.pop(), ++cnt;
            if (X < min(V[i], Y)) { cnt = -1; break; }
            alive.emplace(V[i]);
        }
        cout << cnt << "\n";
    }
    
    return 0;
}