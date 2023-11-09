intervals[idx].max_suffix_sum = max(
    // max suffix sum in left part
    intervals[LEFT_CHILD(idx)].max_suffix_sum + intervals[RIGHT_CHILD(idx)].sum,  
    // max suffix sum in right part
    intervals[RIGHT_CHILD(idx)].max_suffix_sum
);
