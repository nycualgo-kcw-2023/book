struct Interval {
	int L, R;
};

bool compare_function(Interval x, Interval y) {
	return x.L < y.L;
}

int main() {
	// Sort the intervals in ascending order based on R
	sort (interval + 1, interval + 1 + n, compare_function);

	long long intervalValueS[n + 1] = {};
	
	for (int i = 1; i <= n; ++i) {
		int mx = 0;
		for (int j = 1; j < i; j++) {
			if (interval[j].R < interval[i].L)
				mx = max(mx, intervalValueS[j]);	
		}	
		intervalValueS[i] = mx + value[i];
	}
}
