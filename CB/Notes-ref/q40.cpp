//max sum submatrix in a row and columnwise sorted matrix

#include<iostream>
#include<climits>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	int a[100][100];

	for (int row = 0; row < m; row++) {
		for (int col = 0; col < n; col++) {
			cin >> a[row][col];

		}
	}
	for (int row = 0; row < m; row++) {
		for (int col = 0; col < n; col++) {
			cout << a[row][col] << " ";
		}
		cout << endl;
	}
	cout << endl;

	for (int row = m - 1; row >= 0; row--) {
		for (int col = n - 2; col >= 0; col--) {
			a[col][row] += a[col + 1][row];
		}
	}


	for (int row = 0; row < m; row++) {
		for (int col = 0; col < n; col++) {
			cout << a[row][col] << " ";
		}
		cout << endl;
	}

	for (int row = m - 1; row >= 0; row--) {
		for (int col = n - 2; col >= 0; col--) {
			a[row][col] += a[row][col + 1];
		}
	}
	for (int row = 0; row < m; row++) {
		for (int col = 0; col < n; col++) {
			cout << a[row][col] << " ";
		}
		cout << endl;
	}
	cout << endl;

	int max = INT_MIN;

	for (int row = 0; row < m; row++) {
		for (int col = 0; col < n; col++) {
			if (max < a[row][col]) {
				max = a[row][col];
			}
		}

	}
	cout << endl << max << endl;
}