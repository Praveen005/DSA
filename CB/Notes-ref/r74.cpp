#include<iostream>
#include<cmath>
using namespace std;
bool canPlace(int board[][10], int n, int i, int j, int num) {
	for (int k = 0; k < n; k++) {
		if (board[k][j] == num || board[i][k] == num) {
			return false;
		}
	}
	// checking in 3X3 board
	int k = sqrt(n);
	int s = (i / k) * k;
	int l = (j / k) * k;
	for (int x = s; x < s + k; x++) {
		for (int y = l; y < l + k; y++) {
			if (board[x][y] == num) {
				return false;
			}
		}
	}
	return true;

}
bool solve(int board[][10], int n, int i, int j) {
	if (i == n) {
		// print the sudoku board
		for (int k = 0; k < n; k++) {
			for (int l = 0; l < n ; l++) {
				cout << board[k][l] << " ";
			}
			cout << endl;
		}
		return true;
	}
	if (j == n) {
		return solve(board, n, i + 1, 0);
	}
	if (board[i][j] != 0) {
		return solve(board, n, i, j + 1);
	}
	for (int no = 1; no <= 9; no++) {
		if (canPlace(board, n, i, j, no)) {
			board[i][j] = no;
			bool ans = solve(board, n, i, j + 1);
			if (ans) {
				return true;
			}
			board[i][j] = 0;
		}
	}
	return false;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; cin >> n;
	int arr[10][10];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	bool ans = solve(arr, n, 0, 0);
	if (!ans) {
		cout << " NOT POSSIBLE! ";
	}



}

