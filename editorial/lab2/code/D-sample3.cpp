int tree(int l, int r, int l2, int r2) {
    if(r < l) return -1;
    int root = post[r2];
    int rootid = pos[root];
    int lval = tree(l, rootid-1, l2, l2-l+rootid-1);
    int rval = tree(rootid+1, r, r2-r+rootid, r2-1);
    if (lval == -1 && rval == -1) sum += b[root];
    return root;
}
