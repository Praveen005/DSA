//  finding sum of all possible sub matrices
//by getting each element's contribution to the sum
//time complexity  O(n^2)
//space complexity O(1)  because we didn't use extra space

#include<iostream>
using namespace std;
int main() {
	int n = 3, m = 3;
	int val = 1;
	int a[100][100];
	//m rows , n columns
	for (int row = 0; row < m; row++) {
		for (int col = 0; col < n; col++) {
			a[row][col] = val;
			val++;
		}
	}
	int sum = 0;

	//agar kahi confusion ho to dry run kar lo, confusion dur ho jaayega
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			sum += a[i][i] * ((i + 1) * (j + 1) * (m - i) * (n - j));
		}
	}
	cout << sum << endl;
}