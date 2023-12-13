std::vector<int> perm(n);
// for (int i = 0; i < n; ++i) perm[i] = i;
std::iota(begin(perm), end(perm), 0); /// perm = [0, 1, 2, ..., n-1]
do {
    /* do something */
} while (std::next_permutation(begin(perm), end(perm)));
