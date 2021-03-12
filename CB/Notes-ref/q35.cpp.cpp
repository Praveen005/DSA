// brute force approach to finding sum of all possible sub matrices

#include<iostream>
using namespace std;
int main() {
	int n = 3, m = 3;
	int val = 1;
	int a[100][100];
	//filling the matrix
	for (int row = 0; row < m; row++) {
		for (int col = 0; col < n; col++) {
			a[row][col] = val;
			//	val++;
		}
	}
	int sum = 0;
	//extracting top left elements
	//nagar kahi confusion ho to dry run kar lo, confusion dur ho jaayega
	for (int li = 0; li < n; li++) {
		for (int lj = 0; lj < n; lj++) {
			for (int bi = li; bi < m; bi++) {
				for (int bj = lj; bj < n; bj++) {
					for (int i = li; i <= bi; i++) {
						for (int j = lj ; j <= bj; j++) {
							sum += a[i][j];
						}
					}
				}
			}
		}
	}
	cout << sum << endl;
}