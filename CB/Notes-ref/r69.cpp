#include<iostream>
using namespace std;
// i shows the index of current working row

bool getCheese(char input[][15], int output[][15], int n, int m, int i, int j) {
	if (i == n - 1  and j == m - 1  and input[i][j] != 'X') {
		output[i][j] = 1;
		// print the grid/maze

		for (int row = 0; row < n; row++) {
			for (int col = 0; col < m; col++) {
				cout << output[row][col] << " ";
			}
			cout << endl;
		}
		return true;
	}

	// see, there is an issue here
	/*
		if in the following if condition you don't use output==1, then the program will give you a segmentation
		error, due an infinite loop caused due to left and upward movement.
		what will happen?
		if suppose you do i-1, then next function call it will definitely check for i+1
		then again i-1 ans so on ....

		before if-else-if block you see there is ' output[i'[j]=1 '
		meaning this position is visited and marked 1.
		then in i-1, following if() will it will encounter and return false

	*/
	if (i > n - 1  || j > m - 1 || i < 0 || j < 0 || output[i][j] == 1) {

		return false;

	}
	if (input[i][j] == 'X') {
		return false;
	}

	output[i][j] = 1;
	if (getCheese(input, output, n, m, i, j + 1)) {        // RIGHT
		return true;
	}
	else if (getCheese(input, output, n, m, i + 1, j) ) {  // DOWN
		return true;
	}






	else if (getCheese(input, output, n, m, i, j - 1) ) { // DOWn

		return true;
	}

	else if (getCheese(input, output, n, m, i - 1, j) ) {  // DOWN

		return true;
	}







	else {
		output[i][j] = 0;
	}

	return false;
}
int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// n-rows and m- columns
	int n, m;
	cin >> n >> m;
	char input[15][15];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> input[i][j];
		}
	}

	int output[15][15] = {0};

	bool ans = getCheese(input, output, n, m, 0, 0);
	if (!ans) {
		cout << "NO PATH FOUND";
	}
	return 0;
}
