int mex(vector<int> &vec) {
	// vec is sorted.
	// all elements in vec is non-negative and unique
	int N = vec.size();
	for (int i = 0; i < N; ++i) {
		if (vec[i] != i) return i;
	}
	return N;
}
