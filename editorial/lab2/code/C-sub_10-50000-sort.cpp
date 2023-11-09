Number two_increasing_arrays(int n, int k, vector<Number> a, vector<Number> b) {
    copy(begin(b), end(b), back_inserter(a));
    sort(begin(a), end(a));
    return a[k-1];
}
