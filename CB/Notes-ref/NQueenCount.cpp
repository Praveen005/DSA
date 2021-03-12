#include<iostream>
#include<bitset>
using namespace std;
bitset<20>ld, rd, cc;
// bool safeToPlaceQueen(int board[][10], int i, int j, int n) {
// 	// no queen should be present in the current column,j
// 	for (int row = 0; row <= i; row++) {
// 		if (board[row][j] == 1) {
// 			return false;
// 		}
// 	}
// 	// no queen should be present in the left diagonal
// 	int x = i;
// 	int y = j;
// 	while (x >= 0 and y >= 0) {
// 		if (board[x][y] == 1) {
// 			return false;
// 		}
// 		x--;
// 		y--;
// 	}
// 	// no queen should be present along the right diagonal
// 	x = i;
// 	y = j;
// 	while (x >= 0 and y < n) {
// 		if (board[x][y] == 1) {
// 			return false;
// 		}
// 		x--;
// 		y++;
// 	}
// 	// If you return false, it will print all the valid CONFIGURATIONS. YES ALL !!
// 	return true;

// }
int  NQueen(int board[][10], int i, int n) {
	if (i == n) {
		// you have successfully place dn queen  0...(n-1)
		// print the board
		for (int row = 0; row < n; row++) {
			for (int col = 0; col < n; col++) {
				if (board[row][col] == 1) {
					cout << "Q ";
				}
				else {
					cout << "_ ";
				}
			}
			cout << endl;
		}
		cout << endl;

		return 1;
	}
	// RECURSIVE CASE
	//Try to place the queen in the current row and call on the remaining part which will be solved by recursion
	int cnt = 0;
	for (int j = 0; j < n; j++) {
		// I have to check if i,j th position is safe to place the queen or not
		// if (safeToPlaceQueen(board, i, j, n)) {
		if (!ld[(i - j + n - 1)] and !rd[i + j] and !cc[j]) {
			ld[i - j + n - 1] = 1;
			rd[i + j] = 1;
			cc[j] = 1;
			//Place the queen - assuming it is the right position
			board[i][j] = 1;
			cnt += NQueen(board, i + 1, n);

			ld[i - j + n - 1] = 0;
			rd[i + j] = 0;
			cc[j] = 0;
			board[i][j] = 0;

		}
	}
	return cnt;

}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

#endif
	int n; cin >> n;
	int board[10][10] = {0};
	cout << NQueen(board, 0, n);
	// cout << 5 & (-5) << endl;

}





