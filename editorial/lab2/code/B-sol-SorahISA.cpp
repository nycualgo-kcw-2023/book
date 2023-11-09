#include <bits/stdc++.h>
using namespace std;

#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    int N, Q; cin >> N >> Q;
    
    vector<int> arr(N+1);
    for (int i = 1; i <= N; ++i) cin >> arr[i];
    
    vector<pair<int, int>> ch(2*N);
    vector<int> sum(2*N), pmx(2*N), smx(2*N);
    
    function<int(int, int, int&)>
    init = [&](int L, int R, int &tok) {
        int id = tok++;
        if (L == R) {
            ch[id] = {-1, -1};
            sum[id] = arr[L];
            pmx[id] = smx[id] = max(arr[L], int(0));
            return id;
        }
        
        int M = (L + R) >> 1;
        int id_l = init(L, M, tok);
        int id_r = init(M+1, R, tok);
        
        ch[id] = {id_l, id_r};
        sum[id] = sum[id_l] + sum[id_r];
        pmx[id] = max(pmx[id_l], sum[id_l] + pmx[id_r]);
        smx[id] = max(smx[id_r], sum[id_r] + smx[id_l]);
        return id;
    };
    
    function<void(int, int, int, int, int)>
    modify = [&](int p, int v, int L, int R, int id) {
        if (L == R) {
            arr[L] = v;
            sum[id] = arr[L];
            pmx[id] = smx[id] = max(arr[L], int(0));
            return;
        }
        
        auto [id_l, id_r] = ch[id];
        
        int M = (L + R) >> 1;
        if (p <= M) modify(p, v, L, M, id_l);
        if (p >  M) modify(p, v, M+1, R, id_r);
        
        sum[id] = sum[id_l] + sum[id_r];
        pmx[id] = max(pmx[id_l], sum[id_l] + pmx[id_r]);
        smx[id] = max(smx[id_r], sum[id_r] + smx[id_l]);
    };
    
    function<void(int, int, int, int, int, vector<int>&)>
    query = [&](int l, int r, int L, int R, int id, vector<int> &ids) {
        if (l <= L and R <= r) {
            ids.emplace_back(id);
            return;
        }
        
        auto [id_l, id_r] = ch[id];
        
        int M = (L + R) >> 1;
        if (l <= M) query(l, r, L, M, id_l, ids);
        if (r >  M) query(l, r, M+1, R, id_r, ids);
    };
    
    {int tok = 0; init(1, N, tok);}
    
    for (int q = 1; q <= Q; ++q) {
        int op; cin >> op;
        if (op == 1) {
            int k, u; cin >> k >> u;
            modify(k, u, 1, N, 0);
        }
        else {
            int ql, qr; cin >> ql >> qr;
            vector<int> ids; query(ql, qr, 1, N, 0, ids);
            int _sum = 0, _pmx = 0, _smx = 0;
            for (int id : ids) {
                _pmx = max(_pmx, _sum + pmx[id]);
                _smx = max(_smx + sum[id], smx[id]);
                _sum += sum[id];
            }
            if (op == 2) cout << _sum << "\n";
            if (op == 3) cout << _pmx << "\n";
            if (op == 4) cout << _smx << "\n";
        }
    }
    
    return 0;
}
