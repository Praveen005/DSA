#include <iostream>
#include<algorithm>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w", stdout);
#endif
	int n; cin >> n;
	int a[100007];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int q;
	cin >> q;
	int b[q];
	for (int i = 0; i < q; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < q; i++) {

		auto it = lower_bound(a, a + n, b[i]) - a;
		auto it1 = upper_bound(a, a + n, b[i]) - a;
		if (!(binary_search(a, a + n, b[i]))) {
			cout << -1 << " " << -1 << endl;
		}
		else {
			cout << it << " " << it1 - 1 << endl;
		}
	}
}
