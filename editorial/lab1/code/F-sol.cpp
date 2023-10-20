#include <bits/stdc++.h>
using namespace std;

#define int int64_t

const int INF = INT_MAX; /// 501500999
const int maxp = 1000 + 5;

struct Laffey {int d, e, p;};

vector<vector<int>> GCD;

int explore(int N, vector<Laffey> w, int K, vector<Laffey> s) {
    
    auto sum = [](int L, int R) -> int {return R*(R+1)/2 - (L-1)*L/2;};
    
    auto alive = [&](int i, int a) -> bool {
        int endurance = w[i].e;
        for (int j = 0; j < K; ++j) {
            int get_hit = (s[j].e - 1) / w[i].d;
            if (a >= get_hit) {
                /// s[j].d - a, s[j].d - a + 1, ..., s[j].d - a + get_hit - 1 ///
                endurance -= sum(max(s[j].d - a, int(0)), max(s[j].d - a + get_hit - 1, int(0)));
                a -= get_hit, get_hit = 0;
            }
            else if (a) {
                /// s[j].d - a, s[j].d - a + 1, ..., s[j].d - 1 ///
                endurance -= sum(max(s[j].d - a, int(0)), s[j].d - 1);
                get_hit -= a, a = 0;
            }
            endurance -= get_hit * s[j].d;
            if (endurance <= 0) return false;
        }
        return true;
    };
    
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < K; ++j) s[j].d += GCD[w[i].p][s[j].p], s[j].e += GCD[w[i].p][s[j].p];
        
        if (!alive(i, ans)) {
            int lo = ans + 1, hi = INF, mi;
            while (lo < hi) {
                mi = (lo + hi) >> 1;
                if (alive(i, mi)) hi = mi;
                else              lo = mi + 1;
            }
            ans = lo;
        }
        
        for (int j = 0; j < K; ++j) s[j].d -= GCD[w[i].p][s[j].p], s[j].e -= GCD[w[i].p][s[j].p];
    }
    
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    int N, K; cin >> N >> K;
    
    vector<Laffey> w(N), s(K);
    for (auto &[d, e, p] : w) cin >> d;
    for (auto &[d, e, p] : w) cin >> e;
    for (auto &[d, e, p] : w) cin >> p;
    for (auto &[d, e, p] : s) cin >> d;
    for (auto &[d, e, p] : s) cin >> e;
    for (auto &[d, e, p] : s) cin >> p;
    
    GCD.assign(maxp, vector<int>(maxp, 0));
    for (int i = 1; i < maxp; ++i) {
        for (int j = 1; j < maxp; ++j) GCD[i][j] = gcd(i, j);
    }
    
    /// remove these two lines for Subtask 1,2,3 ///
    mt19937_64 rng(1615); /// random seed = 1615
    shuffle(begin(w), end(w), rng);
    
    int res = explore(N, w, K, s);
    cout << res << "\n";
    
    return 0;
}
