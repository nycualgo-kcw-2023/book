#include <bits/stdc++.h>
using namespace std;

// The maximum grid for this problem is 1024.
// So we can declare as a global variable with size 1024 * 1024. 
int grid[1024][1024];

void fillGrid(int num, int row, int col, int size) {
    // If the size of grid is 1 x 1 then fill the answer num in corresponding row and col.
		if (size == 1) {
        grid[row][col] = num;
        return;
    }
		// If the size of grid is not 1 x 1, recursive and fill the number.
    int newSize = size / 2;
		// Top-left grid
    fillGrid(num, row, col, newSize);
		// Top-right grid
    fillGrid(num + newSize * newSize, row, col + newSize, newSize);
	  // Bottom-left grid		
		fillGrid(num + 2 * newSize * newSize, row + newSize, col, newSize);
    // Bottom-right grid		
		fillGrid(num + 3 * newSize * newSize, row + newSize, col + newSize, newSize);
}

int main() {
    int n;
    cin >> n;
		
		// N respond the size of the grid.
		int N = 1;
		for (int i = 1; i <= n; i++) {
			  N = 2 * N;
		}
		// Recursive the gird
    fillGrid(1, 0, 0, N);

    // Output the filled grid
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
