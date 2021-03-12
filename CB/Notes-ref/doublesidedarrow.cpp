// double sided arrow pattern
#include<iostream>
using namespace std;
int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//n will be odd
	int n; cin >> n;

	//upper half
	for (int i = 1 ; i <= (n + 1) / 2; i++ ) {
		for (int j = 1; j <= n - 1 - (2 * (i - 1)); j++) {
			cout << "  ";
		}
		for (int k = i; k >= 1; k--) {
			cout << k << " ";
		}
		for (int l = 0; l < (2 * (i - 1) - 1); l++) {
			cout << "  ";
		}
		for (int m = 1; m <= i && i != 1 ; m++) {
			cout << m << " ";
		}
		cout << endl;
	}
	//lower half

	for (int i = 1; i <= (n - 1) / 2; i++) {
		for (int j = 1; j <= 2 * i ; j++) {
			cout << "  ";
		}
		for (int k = (n - 1) / 2 + 1 - i ; k > 0; k-- ) {
			cout << k << " ";
		}
		for (int l = n - 2 - (2 * i) ; l > 0; l--) {
			cout << "  ";
		}
		for (int m = 1 ; m < (n - 1) / 2 + 2 - i && i !=  (n - 1) / 2; m++) {
			cout << m << " ";
		}
		cout << endl;
	}

}
/*
                            1
                        2 1   1 2
                    3 2 1       1 2 3
                4 3 2 1           1 2 3 4
                    3 2 1       1 2 3
                        2 1   1 2
                            1

       */