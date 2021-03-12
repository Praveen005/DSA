//counting sort
#include <iostream>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);

	freopen("output.txt" , "w", stdout);
#endif
	int n; cin >> n;
	int a[n];
	int digit[1000001] = {0};
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		digit[a[i]]++;
	}
	for (int i = 1; i < 1000001; i++) {
		digit[i] += digit[i - 1];
	}
	int p[n];
	for (int i = 0; i < n; i++) {
		p[digit[a[i]] - 1] = a[i];
		digit[a[i]]--;
	}
	for (int i = 0; i < n; i++) {
		cout << p[i] << " ";
	}
}
//-9, 1, 2, 7, 3, 6, -17