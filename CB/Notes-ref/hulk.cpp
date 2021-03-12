//  incredible hulk

/* niave approach

#include<iostream>
using namespace std;
int check(int n) {
	int count = 0;
	while (n > 1) {
		int i = 0;
		int c = 0;
		while (c <= n) {
			c = (1 << i);
			i++;
		}
		c = (1 << (i - 2));
		n = n - c;
		count++;
	}
	if (n != 0)
		count++;

	return count;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t; cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << check(n) << endl;
	}
}

*/


// incredible hulk
#include<iostream>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		cout << __builtin_popcount(n) << endl;
	}
}