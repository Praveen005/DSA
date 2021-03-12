#include<iostream>
#include<cmath>
using namespace std;


bool canPlace(int mat[][9], int i, int j, int n, int num) {
	// check along the rows and column if or not same number is present
	for (int x = 0; x < n; x++) {
		if (mat[i][x] == num || mat[x][j] == num) {
			return false;
		}
	}
	// Now will check through the sub-grid
	int k = sqrt(n);
	int s = (i / k) * k;
	int l = (j / k) * k;
	for (int x = s; x < s + k; x++) {
		for (int y = l; y < l + k; y++) {
			if (mat[x][y] == num) {
				return false;
			}
		}
	}
	return true;
}
bool solveSudoku(int mat[][9], int i, int j, int n) {
	// base case
	// cout << n << endl;
	if (i == n) {
		// print the mat
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}
		return true;
	}
	//  once you reach the row end go to the next row
	if (j == n) {
		return solveSudoku(mat, i + 1, 0, n);
	}
	// leave the already filled positions
	if (mat[i][j] != 0) {
		return solveSudoku(mat, i, j + 1, n);
	}

	// Now we need to fill the empty places
	for (int num = 1; num <= n; num++) {
		// cout << "2";
		if (canPlace(mat, i, j, n, num)) {
			mat[i][j] = num;
			bool bakiLOg = solveSudoku(mat, i, j + 1, n);
			if (bakiLOg == true) {
				return true;
			}
		}
	}
	//Backtrack
	mat[i][j] = 0;
	return false;
}
int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	int mat[9][9] = {
		{3, 0, 6, 5, 0, 8, 4, 0, 0},
		{5, 2, 0, 0, 0, 0, 0, 0, 0},
		{0, 8, 7, 0, 0, 0, 0, 3, 1},
		{0, 0, 3, 0, 1, 0, 0, 8, 0},
		{9, 0, 0, 8, 6, 3, 0, 0, 5},
		{0, 5, 0, 0, 9, 0, 6, 0, 0},
		{1, 3, 0, 0, 0, 0, 2, 5, 0},
		{0, 0, 0, 0, 0, 0, 0, 7, 4},
		{0, 0, 5, 2, 0, 6, 3, 0, 0}
	};
	solveSudoku(mat, 0, 0, 9);
}
