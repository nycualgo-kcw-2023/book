#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    int N; cin >> N;
    
    for (int r = 0; r < (1<<N); ++r) {
        for (int c = 0; c < (1<<N); ++c) {
            int val = 1;
            for (int bit = 0; bit < N; ++bit) {
                if (r >> bit & 1) val += (1 << (2*bit+1));
                if (c >> bit & 1) val += (1 << (2*bit));
            }
            cout << val << " \n"[c == (1<<N)-1];
        }
    }
    
    return 0;
}
