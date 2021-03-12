

#include<iostream>
#include<cstring>
using namespace std;

//BASE CASE
bool ratInMaze(char maze[10][10], int soln[10][10], int i, int j, int m, int n) {
	if (i == m && j == n) {
		soln[m][n] = 1;
		for (int i = 0; i <= m; i++) {
			for (int j = 0; j <= n; j++) {
				cout << soln[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	//Rat should not venture out of the maze

	if (i > m || j > n) {
		return false;
	}

	// Rat shouldn't hit a road block

	if (maze[i][j] == 'x') {
		return false;
	}
	soln[i][j] = 1;
	//RECURSIVE CASE
	bool rightsuccess = ratInMaze(maze, soln, i, j + 1, m, n);
	bool leftsuccess = ratInMaze(maze, soln, i + 1, j, m, n);

	//BACKTRACKING
	soln[i][j] = 0;
	if (rightsuccess || leftsuccess) {
		return true;
	}
	return false;
}
int main() {
/*
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
*/

	char maze[10][10] = {"x000",
	                     "00x0",
	                     "000x",
	                     "0x00"
	                    };
	//we wish to print all the possible paths

	int output[10][10] = {0};
	int m = 4, n = 4;
	bool ans = ratInMaze(maze, output, 0, 0, m - 1, n - 1);

	return 0;

}
