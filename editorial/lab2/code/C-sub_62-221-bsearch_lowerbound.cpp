Number two_increasing_arrays(int n, int k, vector<Number> a, vector<Number> b) {
    --k;
    for (int lo = 0, hi = n-1, mi; lo <= hi; ) {
        mi = (lo + hi) >> 1;
        int small_a = mi;
        int small_b = lower_bound(begin(b), end(b), a[mi]) - begin(b);
        if (small_a + small_b == k) return a[mi];
        if (small_a + small_b < k) lo = mi + 1;
        else                       hi = mi - 1;
    }
    for (int lo = 0, hi = n-1, mi; lo <= hi; ) {
        mi = (lo + hi) >> 1;
        int small_a = lower_bound(begin(a), end(a), b[mi]) - begin(a);
        int small_b = mi;
        if (small_a + small_b == k) return b[mi];
        if (small_a + small_b < k) lo = mi + 1;
        else                       hi = mi - 1;
    }
}
