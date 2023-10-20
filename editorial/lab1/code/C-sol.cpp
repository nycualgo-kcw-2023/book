#include "1612.h"

int convex_hull(int L, int k) {
    
    int lo = -1'000'000'000, hi = 1'000'000'000, mi;
    while (lo < hi) {
        mi = (lo + hi) >> 1;
        auto [x, y] = query(mi);
        if (x == k) return y;
        if (x < k) hi = mi;
        else       lo = mi + 1;
    }
    
    auto [x, y] = query(lo);
    return y + (k - x) * lo;
}
