int solve(int L0, int L1, int R0, int R1) {
    int ans = 0;
    for (int l = L1, mx = a[L1]; l >= L0; --l) {
        mx = max(mx, a[l]);
        if (R0 <= mx + l - k and mx + l - k <= R1) ++ans;
    }
    return ans;
}
