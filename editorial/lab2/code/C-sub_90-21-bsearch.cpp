Number two_increasing_arrays(int n, int k, vector<Number> a, vector<Number> b) {
    --k;
    int len = 2*n, al = 0, ar = n-1, am, bl = 0, br = n-1, bm;
    
    while (al < ar and bl < br) {
        am = (al + ar + (2*k >= len)) >> 1;
        bm = (bl + br + (2*k >= len)) >> 1;
        if (a[am] < b[bm]) {
            if (2*k >= len) {
                len -= am - al;
                k -= am - al;
                al = am;
            }
            else {
                len -= br - bm;
                br = bm;
            }
        }
        else {
            if (2*k >= len) {
                len -= bm - bl;
                k -= bm - bl;
                bl = bm;
            }
            else {
                len -= ar - am;
                ar = am;
            }
        }
    }
    
    if (al == ar and bl == br) {
        if (k == 0) return min(a[al], b[bl]);
        if (k == 1) return max(a[al], b[bl]);
    }
    if (k == 0) {
        return (a[al] < b[bl] ? a[al] : b[bl]);
    }
    if (al < ar) {
        return (b[bl] < a[al+k-1] ? a[al+k-1] : (b[bl] < a[al+k] ? b[bl] : a[al+k]));
    }
    if (bl < br) {
        return (a[al] < b[bl+k-1] ? b[bl+k-1] : (a[al] < b[bl+k] ? a[al] : b[bl+k]));
    }
}
