using ll = long long;
struct Matrix {
  int n, m, val[15][15];
  Matrix() {
    n = m = 1;
    memset(val, 0, sizeof(val));
  }

  Matrix operator * (const Matrix &b) const {
    Matrix res;
    res.n = n;
    res.m = b.m;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= b.m; j++) {
        for (int k = 1; k <= m; k++) {
          res.val[i][j] += val[i][k] * b.val[k][j];
        }
      }
    }
    return res;
  }
};

int main() {
	// Input u, v, A
	// u is a scalar
	// A is a vector of size 1 x m
	ll maxVal = -1e18;
	vector<int> bestV;
	sort (v.begin(), v.end());
	do {
	    for (int i = 0; i < m; i++) {
	        V.val[i + 1][1] = v[i];
	    }
	    if (maxVal < (U * A * V).val[1][1]) {
	        maxVal = (U * A * V).val[1][1];
	        bestV = v;
	    }
	}while(next_permutation(v.begin(), v.end()));
	// out maxVal
	// out u
	// put bestv
	// out A
}
