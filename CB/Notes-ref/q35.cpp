// finding sum of all possible sub matrices  --> 2nd approach
//time complexity is O(n^4)
//space complexity O(1)  because we didn't use extra space

#include<iostream>
using namespace std;
int main() {
	int n = 4, m = 4;
	int val = 1;
	int a[100][100];
	//filling the matrix
	for (int row = 0; row < m; row++) {
		for (int col = 0; col < n; col++) {
			a[row][col] = val;
			val++;
		}
	}
	for (int row = 0; row < m; row++) {
		for (int col = 0; col < n; col++) {
			cout << a[row][col] << " ";

		}
		cout << endl;
	}
	cout << endl;
	// row-wise add kar rahe to get cumulative sum
	//matlab row constant rakh kar

	for (int row = 0; row < m; row++) {
		for (int col = 1; col < n; col++) {
			//	a[row][-1] = 0;
			a[row][col] += a[row][col - 1];

		}
	}
	for (int row = 0; row < m; row++) {
		for (int col = 0; col < n; col++) {
			cout << a[row][col] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
	// column-wise add kar rahe to get cumulative sum
	//matlab column constant rakh kar
	for (int row = 0; row < m; row++) {
		for (int col = 1; col < n; col++) {
			//	a[-1][row] = 0;
			a[col][row] += a[col - 1][row];
		}
	}
	for (int row = 0; row < m; row++) {
		for (int col = 0; col < n; col++) {
			cout << a[row][col] << " ";
		}
		cout << endl;
	}
	int sum = 0;
	int li, lj;
	//extracting top left elements
	//magar kahi confusion ho to dry run kar lo, confusion dur ho jaayega
	for ( li = 0; li < n; li++) {
		for (lj = 0; lj < n; lj++) {
			for (int bi = li; bi < m; bi++) {
				for (int bj = lj; bj < n; bj++) {

					if (li == 0 && lj != 0) {
						sum += (a[bi][bj] - a[bi][lj - 1]);
					}
					else if (li != 0 && lj == 0) {
						sum += (a[bi][bj] - a[li - 1][bj]);
					}
					else if (li == 0 && lj == 0) {
						sum += (a[bi][bj]);
					}
					else {
						sum += (a[bi][bj] - a[bi][lj - 1] - a[li - 1][bj] + a[li - 1][lj - 1]);

					}
				}
			}
		}
	}
	cout << sum << endl;
}