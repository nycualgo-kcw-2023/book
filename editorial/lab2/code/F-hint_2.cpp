int solve(int L, int R) {
    int M = (L + R) >> 1;
    int L0 = L, L1 = M, R0 = M+1, R1 = R;
    
    int ans = 0;
    /* calculate answer */
    return solve(L, M) + solve(M+1, R) + ans;
}
