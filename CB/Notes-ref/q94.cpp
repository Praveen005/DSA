#include<iostream>
using namespace std;
int sbits(int s[] , int n ) {
	int i = 0;
	while (n > 0) {
		s[i] += (n & 1);
		i++;
		n = n >> 1;
	}
	return i;
	// i-1 represents last set bit index
}
int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
// unique number III

	int n; cin >> n;
	int a[100009];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int s[100009] = {0};
	int c;
	for (int i = 0; i < n; i++) {
		c = sbits(s, a[i]);
	}
	int number = 0;
	for (int i = 0; i < c; i++) {
		number += ((s[i] % 3) * (1 << i));
	}
	cout << number << endl;

}