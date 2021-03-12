// unique number 1

#include<iostream>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n; cin >> n;
	int a[100009];
	int c = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		c = (c ^ a[i]);
	}
	cout << c << endl;
}