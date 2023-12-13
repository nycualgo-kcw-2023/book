void recur(int n, int last, ...) {
    if (n == last) {
        /// all people are partitioned ///
    }
    else {
        for (int now = last + 2; now <= n; ++now) {
            /// [last, now) is in the same group ///
            recur(n, now, ...);
        }
    }
}

recur(n, 0, ...);
