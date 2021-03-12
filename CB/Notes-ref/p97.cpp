//median of two array problem
//if even no of digits then do average of (n/2) & ((n/2)+1)  th digit.
//matlab jo average aaya woth digit chahiye
//-1 karna mat bhulna, wo array ka indexing :)

#include<iostream>
#include<algorithm>
using namespace std;
int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int a[n];
	int b[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	int c[100];
	for (int i = 0; i < 2 * n; i++) {
		if (i < n) {
			c[i] = a[i];
		}
		else {
			c[i] = b[i - n];
		}
	}

	sort(c, c + 2 * n);
	int size = 1;

	for (int i = 1; i < 2 * n; i++) {
		// c[i]=c[i];
		if (c[i] == c[i - 1]) {
			continue;
		}
		c[size] = c[i];
		size++;
	}
	// for (int i = 0; i < size; i++) {
	// 	cout << c[i] << "  ";
	// }
	// cout << endl << size << endl;
	if (size % 2 == 0) {
		cout << c[((size / 2) + (size / 2 + 1)) / 2 - 1];
	}
	else {
		cout << c[((size + 1) / 2) - 1] << endl;
	}


}