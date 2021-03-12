#include<iostream>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w", stdout);
#endif
	int n;
	cin >> n;
	int no = 0;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		no = (no ^ a[i]);
	}

	//now find the position of first set bit in 'no'
	int posn = 0;
	while ((no & 1) == 0) {
		posn++;
	}
	//now we have to check which nos has the 1st set bit position 'posn'
	int mask = (1 << posn);
	int x = 0;
	for (int i = 0; i < n; i++) {
		if ((a[i]&mask) > 0) {
			x = (x ^ a[i]);

		}
	}

	int y = (x ^ no);
	cout << min(x, y) << " " << max(x, y) << endl;



}