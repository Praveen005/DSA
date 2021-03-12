
/*



A knight is a piece used in the game of chess. The chessboard itself is square array of cells. Each time a knight moves, its resulting position is two rows and one column, or two columns and one row away from its starting position. Thus a knight starting on row r, column c – which we’ll denote as (r,c) – can move to any of the squares (r-2,c-1), (r-2,c+1), (r-1,c-2), (r-1,c+2), (r+1,c-2), (r+1,c+2), (r+2,c-1), or (r+2,c+1). Of course, the knight may not move to any square that is not on the board.

Suppose the chessboard is not square, but instead has rows with variable numbers of columns, and with each row offset zero or more columns to the right of the row above it. The figure ( https://bit.ly/3irYcNa ) illustrates one possible configuration. How many of the squares in such a modified chessboard can a knight, starting in the upper left square (marked with an asterisk), not reach in any number of moves without resting in any square more than once? Minimize this number.



If necessary, the knight is permitted to pass over regions that are outside the borders of the modified chessboard, but as usual, it can only move to squares that are within the borders of the board.

Input Format
First line contains an integer n, representing the side of square of chess board. The next n line contains n integers separated by single spaces in which jjth integer is 1 if that cell(i,j) is part of chessboard and 0 otherwise.

Constraints
The maximum dimensions of the board will be 10 rows and 10 columns. That is, any modified chessboard specified by the input will fit completely on a 10 row, 10 column board.

Output Format
Print the minimum number of squares that the knight can not reach.

Sample Input
3
1 1 1
1 1 1
1 1 1

Sample Output
1

sample Input
10
1 1 1 1 1 1 1 1 1 1
0 0 1 1 1 1 1 0 0 0
0 0 0 0 1 1 0 0 0 0
0 1 1 0 0 0 0 0 0 0
0 1 1 1 1 1 1 0 0 0
0 0 0 0 1 1 0 0 0 0
0 0 0 0 0 0 1 1 1 0
0 0 0 0 0 0 0 1 1 0
0 1 1 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 1 1

sample output
17

*/
/*

My Assesment:  The only issue I faced was in comprehending the line “in any number of moves without resting in any square more than once? Minimize this number.”



It means You have to cover max number of boxes in single traversal(one continuous move until to can’t move anymore).

suppose I started moving, now in one traversal, I covered 14 out of 24 valid boxes. Now I will backtrack again to initial position and start afresh along (one of those 8 valid movements for a knight). Now suppose I covered 16 out of valid 24 valid boxes. We will keep repeating this and storing the max out of the boxes covered in each traversal (14,16,…).

Now after exhausting all the possible moves, we have the value of max boxes that we could cover in a single (non-stop) move. We will subtract this max value from the total valid boxes on the board to get the number of boxes that we couldn’t move to(This value would be the minimum out of all possible traversals that we made).



*/





#include<iostream>
#include<algorithm>
#include<set>
#include<string>
using namespace std;

int x[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int ans = 0;
void place(int in[][25], int n, int i, int j, int count) {
	if (i < 0 || i >= n || j < 0 || j >= n || in[i][j] == 0) {
		return;
	}
	in[i][j] = 0;
	ans = max(ans, count + 1);

	for (int k = 0; k < 8; k++) {
		int row = i + x[k];
		int col = j + y[k];
		place(in, n, row, col, count + 1);
	}
	//Backtrack
	in[i][j] = 1;
}

int main() {

	int n; cin >> n;
	int valid = 0;
	int a[25][25];
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			cin >> a[row][col];
			if (a[row][col]) {
				valid++;
			}
		}
	}
	place(a, n, 0, 0, 0);

	cout << valid - ans << endl;
}

///  Related Problem : SPOJ : MKJUMPS
///  Check : https://github.com/Praveen005/SPOJ-solutions/blob/master/MKJUMPS.cpp




