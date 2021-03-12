#include<iostream>
#include<algorithm>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int sum = 0;
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		sum += a[i] * i;
		//cout << a[i] << " ";
	}

	cout << sum << endl;
}