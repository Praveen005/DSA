// hour glass
#include<iostream>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; cin >> n;
	for (int i = n; i >= 0; i--) {
		for (int l = 1; l <= n - i; l++) {
			cout << "  ";
		}
		for (int j = i; j >= 0; j--) {
			cout << j << " ";
		}
		for (int k = 1; k <= i; k++) {
			cout << k << " ";
		}
		cout << endl;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = n - i; j > 0; j--) {
			cout << "  ";
		}
		for (int k = i; k >= 0; k--) {
			cout << k << " ";
		}
		for (int l = 1; l <= i; l++) {
			cout << l << " ";
		}
		cout << endl;
	}

}