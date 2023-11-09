int fpow(int base, int exp, int mod) {
    int ans = 1 % mod;
    while (exp) {
        if (exp & 1) ans = ans * base % mod;
        exp >>= 1, base = base * base % mod;
    }
    return ans;
}
