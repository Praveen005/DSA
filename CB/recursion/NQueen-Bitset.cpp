// NQueen 
/*
	used bitset to optimise the approach

*/

#include<iostream>
#include<bitset>
using namespace std;
#define ll long long
bitset<30>ld, rd, cc;
void placeQueen(int grid[][10], int n, int i, int &ans) {
	if (i == n) {
		// print the grid
		for (int row = 0; row < n; row++) {
			for (int col = 0; col < n; col++) {
				if (grid[row][col] == 1) {
					cout << "Q ";
				}
				else {
					cout << "_ ";
				}
			}
			cout << endl;
		}
		cout << endl;
		// all the queens have been placed at the desired position
		ans++;
	}
	int rightDiag[20] = {0};
	int leftDiag[20] = {0};
	int column[10] = {0};
	for (int j = 0; j < n; j++) {
		if (!ld[(i - j + n - 1)] and !rd[i + j] and !cc[j]) {
			ld[i - j + n - 1] = 1;
			rd[i + j] = 1;
			cc[j] = 1;
			grid[i][j] = 1;
			placeQueen(grid, n, i + 1, ans);
			//this step is backtarcking
			grid[i][j] = ld[i - j + n - 1] = rd[i + j] = cc[j] = 0;
		}
	}
}
int main() {
/*
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

#endif
*/
	// we are going to solve N-Queen problem
	int n; cin >> n;
	int grid[10][10] = {0};
	int ans = 0;
	placeQueen(grid, n, 0, ans);
	//print the count
	cout << ans << endl;
}
