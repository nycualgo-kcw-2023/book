struct Interval {
	int L, R;
};

bool compare_function(Interval x, Interval y) {
	return x.R < y.R;
}

int main() {
	// Sort the intervals in ascending order based on R
	std::sort(interval + 1, interval + 1 + n, compare_function);
	
	int max_R = -1; // Initially, no interval is selected
	int sizeOfIntervalSet = 0; // Final answer
	
	for (int i = 1; i <= n; ++i) {
		if (interval[i].L > max_R) {
			max_R = interval[i].R;
			sizeOfIntervalSet++;
		}
	}
}
