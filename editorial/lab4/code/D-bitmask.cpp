for (int mask = 0; mask < (1<<n); ++mask) { /// (1<<n) is 2**n
    vector<int> subset;
    for (int bit = 0; bit < n; ++bit) {
        /// check if the i-th bit is 1 ///
        // if (mask & (1 << bit)) subset.emplace_back(bit);
        if ((mask >> bit) & 1) subset.emplace_back(bit);
    }
    /* do something */
}
