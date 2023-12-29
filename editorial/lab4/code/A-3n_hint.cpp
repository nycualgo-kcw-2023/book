int U = (1 << n) - 1;
for (S be the subset of U) { /* and all subset of S is enumerated */
    for (int T = /* complement set of S */; T is non-empty; T = (T-1) & (/* complement set of S */)) {
        if (the number of 1s in T is >= 2) {
            dp[S union T] = min(dp[S union T], dp[S] + cost(T));
        }
    }
}
