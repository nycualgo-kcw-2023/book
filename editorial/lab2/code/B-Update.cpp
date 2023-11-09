void UpdateIntervalSum(int k, int u, int l = 1, int r = n, int idx = 1) {
    // Treat updates as a range query of [k, k] : ql = qr = k

    /*** Case 1 : [l, r] == [k, k] ***/
    if (k <= l && r <= k) {  // leaf node, same as (l == k && r == k)
        intervals[idx].sum = u;
        return;
    }

    /*** Case 2 : [l, r] is entirely outside [k, k] ***/
    if (k < l || k > r)  // not affected by update
        return;

    /*** Case 3 : affected by update, divide [l, r] into two parts ***/
    int m = (l + r) / 2; // divide
    
    Update(k, u, l, m, LEFT_CHILD(idx)); // conquer left part
    Update(k, u, m + 1, r, RIGHT_CHILD(idx)); // conquer right part

    // Update the sum of current interval by merging the result of left and right part
    intervals[idx].sum = intervals[LEFT_CHILD(idx)].sum + intervals[RIGHT_CHILD(idx)].sum;
}
