#include<iostream>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w", stdout);
#endif
	int m , n;
	m = 9, n = 8;

	//cin >> m >> n;
	//m rows  n columns
	int a[100][100];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	int startCol = 0, endCol = n - 1, startRow = 0, endRow = m - 1;
	while (startRow <= endRow && startCol <= endCol) {
		for (int i = startRow ; i <= endRow; i++) {
			cout << a[i][startCol] << ", ";
		}
		startCol++;
		if (startCol <= n - 1) {
			for (int j = endRow; j >= startRow; j--) {
				cout << a[j][startCol] << ", ";
			}
		}
		startCol++;


	}
	cout << "END";


}