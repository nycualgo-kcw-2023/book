int solve(int L0, int L1, int R0, int R1) {
    int ans = 0;
    
    map<int, int> costR;
    for (int r = R0, mn = a[R0]; r <= R1; ++r) {
        mn = min(mn, a[r]);
        ++costR[mn + r];
    }
    
    for (int l = L1, mx = a[L1]; l >= L0; --l) {
        mx = max(mx, a[l]);
        ans += costR[mx + l - k];
    }
    
    return ans;
}
