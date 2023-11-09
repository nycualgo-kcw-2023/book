intervals[idx].max_prefix_sum = max(
    // max prefix sum in left part
    intervals[LEFT_CHILD(idx)].max_prefix_sum,                                   
    // max prefix sum in right part
    intervals[LEFT_CHILD(idx)].sum + intervals[RIGHT_CHILD(idx)].max_prefix_sum
);
