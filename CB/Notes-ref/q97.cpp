
#include<iostream>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t; cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i * i <= n ; i += 2) {
			for (int j = 1; j * j <= n; j += 2) {
				if (i * i + j * j == n) {
					cout << "(" << min(i, j) << "," << max(i, j) << ")" << " ";
				}

			}

		}
		for (int i = 0; i * i <= n / 2 ; i += 2) {
			for (int j = 0; j * j <= n ; j += 2) {
				if (i * i + j * j == n) {
					cout << "(" << min(i, j) << "," << max(i, j) << ")" << " ";
				}
			}
		}

		for (int i = 1; i * i <= n / 2 ; i += 2) {
			for (int j = 1; j * j <= n; j += 2) {
				if (i * i + j * j == n) {
					cout << "(" << min(i, j) << "," << max(i, j) << ")" << " ";
				}
			}
		}
		cout << endl;
	}

}