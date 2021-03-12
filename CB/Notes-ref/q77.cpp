#include<iostream>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w", stdout);
#endif
	int m; int n;
	//m rows   &   n columns
	cin >> m >> n;
	int a[100][100];
	int val = 1;
	for (int row = 0; row < m; row++) {
		for (int col = 0; col < n; col++) {
			a[row][col] = val;
			val++;
		}
	}

	for (int row = 0; row < m; row++) {
		for (int col = 0 ; col < n; col++) {
			cout << a[row][col] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int row = 0; row < m; row++) {
		for (int col = 1 ; col < n; col++) {

		}
	}

	for (int row = 0; row < m; row++) {
		for (int col = 0 ; col < n; col++) {
			cout << a[row][col] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int row = 0; row < m; row++) {
		for (int col = 1 ; col < n; col++) {
			a[col][row] += a[col - 1][row];

		}

	}


	for (int row = 0; row < m; row++) {
		for (int col = 0 ; col < n; col++) {
			cout << a[row][col] << " ";
		}
		cout << endl;
	}
}