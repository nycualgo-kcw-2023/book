int fpow(int base, int exp, int mod) {
    if (exp == 0) return 1 % mod;
    int half = fpow(base, exp/2, mod);
    // return half * half % mod * (exp & 1 ? base : 1) % mod;
    if (exp % 2 == 0)
        return half * half % mod;
    else /// remember to take mod to reduce the maximum value during calculation ///
        return half * half % mod * base % mod;
    /*                     ^^^^^                                                  */
}
