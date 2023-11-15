int ans = 0;
for (int l = 0; l < n; ++l) {
    for (int r = l, mn = A[l], mx = A[l]; r < n; ++r) {
        mn = min(mn, A[r]), mx = max(mx, A[r]);
        if ((mx - mn) - (r - l) == k) ++ans;
    }
}
cout << ans << "\n";
