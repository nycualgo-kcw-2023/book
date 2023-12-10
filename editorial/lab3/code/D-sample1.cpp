using ll = long long;

int main() {
    // Input u, v, A
    
    // Calculate u^TA first
    // u^TA has the size of 1 x m
    vector<ll> uTA(m, 0);
    for (int i = 0; i < 1; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < n; ++k) {
                uTA[j] += u[k] * A[k][j];
            }
        }
    }

    // Calculate (u^TA)v
    // (u^TA)v has the size of 1 x 1
    ll val = 0;
    for (int i = 0; i < m; i++) {
        val += uTA[i] * v[i];
    }
    
    cout << val << endl;
    
	// Output the same u, v, A

    return 0;
}
