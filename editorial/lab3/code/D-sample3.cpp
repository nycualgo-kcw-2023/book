using ll = long long;

int main()
{
    // Input u, v, A
	// u is a scalar
	// A is a vector of size 1 x m

    ll max_val = 0;
    if (u > 0) {
        sort(A.begin(), A.end());
    } else {
        sort(A.rbegin(), A.rend());
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < m; ++i) {
        max_val += u * A[i] * v[i];
    }

    cout << max_val << endl;
    
	// Output u, v, A

    return 0;
}
