#include <bits/stdc++.h>
#include <iostream>
#define maxn 2000005
using namespace std;

int n, in[maxn], post[maxn], pos[maxn];
long long b[maxn];

long long sum;
int tree(int l, int r, int l2, int r2) {
    if(r < l) return -1;
    int root = post[r2];
    int rootid = pos[root];
    int lval = tree(l, rootid-1, l2, l2-l+rootid-1);
    int rval = tree(rootid+1, r, r2-r+rootid, r2-1);
    if (lval == -1 && rval == -1) sum += b[root];
    return root;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) cin >> in[i], in[i]--;
    for(int i = 0; i < n; i++) cin >> post[i], post[i]--;

    // index mapping
    for(int i = 0; i < n; i++) pos[in[i]] = i;

    // construct tree
    tree(0, n-1, 0, n-1);

    cout << post[n-1]+1 << '\n' << sum << '\n';
    return 0;
}
