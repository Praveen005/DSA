//Q. playing with bits
#include<iostream>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// Your task is to count the no of set-bits
	// in for all numbers between a and b (both inclusive)

	int q;
	cin >> q;
	while (q--) {
		int a, b;
		int sum = 0;
		cin >> a >> b;
		for (int i = a; i <= b; i++) {
			sum += __builtin_popcount(i);
		}
		cout << sum << endl;
	}
}