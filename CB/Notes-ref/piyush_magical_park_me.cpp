#include<iostream>
using namespace std;
void magical_park(char a[][100] , int m, int n, int k, int s) {
	//int i, j;


	bool success = true;

	for ( int i = 0 ; i < m ; i++) {
		for ( int j = 0 ; j < n ; j++) {
			char ch = a[i][j];
			// threshold energy
			if (k > s) {
				success = false;

				break;
			}


			if (ch == '*') {
				s += 5;
			}
			else if (ch == '.') {
				s -= 2;
			}
			else {
				break;
			}
			if (j != n - 1) {
				s--;
			}
		}
	}
	if (success) {
		cout << "Yes" << endl << s << endl;
	}

	else {
		cout << "No" << endl;
	}
}


int main() {
	int m, n, k, s;
	cin >> m >> n >> k >> s;

	char a[100][100];
	for (int i = 0; i < m; i++) {
		for (int j = 0 ; j < n; j++) {
			cin >> a[i][j];

		}

	}
	magical_park(a, m, n, k, s);
}