#include "1622.h"
#include <bits/stdc++.h>
using namespace std;

Number two_increasing_arrays(int n, int k, vector<Number> a, vector<Number> b) {
    int al = 0, ar = n-1, am, bl = 0, br = n-1, bm;
    
    if (k <= n) ar = br = k-1, k = ar - al + 1;
    if (k >= n+1) al = bl = k-n-1, k = ar -al + 2;
    
    while (al < ar or bl < br) {
        int len = ar - al + 1;
        if (len % 2 == 1) {
            am = (al + ar) >> 1;
            bm = (bl + br) >> 1;
            if (a[am] < b[bm]) {
                al = am;
                br = bm;
                k -= len / 2;
            }
            else {
                ar = am;
                bl = bm;
                k -= len / 2;
            }
        }
        else if (k == len) {
            am = (al + ar) >> 1;
            bm = (bl + br) >> 1;
            if (a[am] < b[bm]) {
                al = am + 1;
                br = bm;
                k -= len / 2;
            }
            else {
                ar = am;
                bl = bm + 1;
                k -= len / 2;
            }
        }
        else if (k == len + 1) {
            am = (al + ar + 1) >> 1;
            bm = (bl + br + 1) >> 1;
            if (a[am] < b[bm]) {
                al = am;
                br = bm - 1;
                k -= len / 2;
            }
            else {
                ar = am - 1;
                bl = bm;
                k -= len / 2;
            }
        }
    }
    
    if (a[al] < b[bl]) return (k == 1 ? a[al] : b[bl]);
    else               return (k == 1 ? b[bl] : a[al]);
}
