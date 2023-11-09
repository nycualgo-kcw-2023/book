int tree(int l, int r, int l2, int r2) {
    if(r < l) return -1;
    int root = post[r2];
    int rootid = pos[root];
    left__[root] = tree(l, rootid-1, l2, l2-l+rootid-1);
    right__[root] = tree(rootid+1, r, r2-r+rootid, r2-1);
    return root;
}

// Index mapping
for(int i = 0; i < n; i++) pos[in[i]] = i;

// Construct tree
tree(0, n-1, 0, n-1);
