Number two_increasing_arrays(int n, int k, vector<Number> a, vector<Number> b) {
    vector<Number> c;
    merge(begin(a), end(a), begin(b), end(b), back_inserter(c));
    return c[k-1];
}
