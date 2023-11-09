long long QuerySum(int &ql, int &qr, int l = 1, int r = n, int idx = 1) {
    /*** Case 1 : [l, r] is entirely inside [ql, qr] ***/
    if (ql <= l && r <= qr) {  // contain by query range
        return intervals[idx].sum;
    }

    /*** Case 2 : [l, r] is entirely outside [ql, qr] ***/
    if (qr < l || r < ql) {
        return 0;  // return 0 won't affect the calculation of sum in parent query
    }

    /*** Case 3 : divide [l, r] into two subproblems ***/
    int m = (l + r) / 2; // divide

    long long left_part_ans = QuerySum(ql, qr, l, m, LEFT_CHILD(idx)); // conquer left part
    long long right_part_ans = QuerySum(ql, qr, m + 1, r, RIGHT_CHILD(idx)); // conquer right part

    return left_part_ans + right_part_ans; // merge the result of left and right part
}
