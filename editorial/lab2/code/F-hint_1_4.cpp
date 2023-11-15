int solve(int L0, int L1, int R0, int R1) {
    int ans = 0;
    
    for (int l = L1, r = R0-1, mx = a[L1]; l >= L0; --l) {
        mx = max(mx, a[l]);
        while (r < R1 and a[r+1] < mx) ++r;
        if (R0 <= mx + l - k and mx + l - k <= r) ++ans;
    }
    
    for (int l = L1+1, r = R0, mx = a[R0]; r <= R1; ++r) {
        mx = max(mx, a[r]);
        while (l > L0 and a[l-1] < mx) --l;
        if (l <= -mx + r + k and -mx + r + k <= L1) ++ans;
    }
    
    return ans;
}
