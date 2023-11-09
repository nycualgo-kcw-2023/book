#define LEFT_CHILD(idx) (idx << 1)
#define RIGHT_CHILD(idx) ((idx << 1) | 1)

void GetIntervalSum(int l = 1, int r = n, int idx = 1){
    if (l == r) {  // leaf node
        intervals[idx].sum = a[l];
        return;
    }

    int m = (l + r) / 2; // divide

    GetIntervalSum(l, m, LEFT_CHILD(idx));      // conquer left part
    GetIntervalSum(m + 1, r, RIGHT_CHILD(idx)); // conquer right part

    // merge the result of left and right part
    intervals[idx].sum = intervals[LEFT_CHILD(idx)].sum + intervals[RIGHT_CHILD(idx)].sum;
}
