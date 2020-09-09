/*

You are given an N*M grid. Each cell (i,j) in the grid is either blocked, or empty. The rat can move from a position towards left, right, up or down on the grid.
Initially rat is on the position (1,1). It wants to reach position (N,M) where it's cheese is waiting for. There exits a unique path in the grid . Find that path and help the rat reach its cheese.


Input Format
First line contains 2 integers N and M denoting the rows and columns in the grid.
Next N line contains M characters each. An 'X' in position (i,j) denotes that the cell is blocked and ans 'O' denotes that the cell is empty.


Constraints
1 <= N , M <= 10

Output Format
Print N lines, containing M integers each. A 1 at a position (i,j) denotes that the (i,j)th cell is covered in the path and a 0 denotes that the cell is not covered in the path.
If a path does not exits then print "NO PATH FOUND"


Sample Input
5 4
OXOO
OOOX
XOXO
XOOX
XXOO
Sample Output
1 0 0 0 
1 1 0 0 
0 1 0 0 
0 1 1 0 
0 0 1 1

Sample Input
5 7
OXOOOOX
OXOXOXX
OXOXOOX
OOOXOXX
XXOXOOO

Sample Output
1 0 1 1 1 0 0 
1 0 1 0 1 0 0 
1 0 1 0 1 0 0 
1 1 1 0 1 0 0 
0 0 0 0 1 1 1 

sample input
4 5
OOXXX
OXOOO
OXOXO
OOOXO

sample output
1 0 0 0 0 
1 0 1 1 1 
1 0 1 0 1 
1 1 1 0 1 


*/




#include<iostream>
using namespace std;
bool solve(char maze[][11], int output[][11], int n, int m, int i, int j) {

	if (i == n - 1 and j == m - 1 and maze[i][j] == 'O') {
		output[i][j] = 1;
		// print the maze
		for (int k = 0; k < n; k++) {
			for (int l = 0; l < m; l++) {
				cout << output[k][l] << " ";
			}
			cout << endl;
		}
		return true;
	}


	if (maze[i][j] == 'X') {
		return false;
	}
	if (i > n - 1 || j > m - 1 || output[i][j] == 1 || i < 0 || j < 0) {
		return false;
	}

	output[i][j] = 1;

	
	if (solve(maze, output, n, m, i + 1, j)) {
		return true;
	}
	else if (solve(maze, output, n, m, i - 1, j)) {
		return true;
	}
	else if (solve(maze, output, n, m, i, j + 1)) {
		return true;
	}
	else if (solve(maze, output, n, m, i, j - 1)) {
		return true;
	}
	else {
		output[i][j] = 0;
	}
	return false;

}
int main() {

	int n, m;
	cin >> n >> m;
	char maze[11][11];
	//n rows and m columns
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maze[i][j];
		}
	}

	int output[11][11] = {0};
	

	bool ans = solve(maze, output, n, m, 0, 0);
	if (!ans) {
		cout << "NO PATH FOUND" << endl;
	}

}
