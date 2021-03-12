//Layman/niave approach  O(n^2)
/*

#include<iostream>
#include<climits>
using namespace std;
int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int a, b;
	cin >> a >> b;
	int mXor = INT_MIN;
	int l, r;

	l = min(a, b);
	r = max(a, b);
	int maxXor = INT_MIN;
	for (int i = l; i <= r; i++) {
		for (int j = i; j <= r; j++) {
			maxXor = max(maxXor, (i ^ j));
		}
	}
	cout << maxXor << endl;
}

*/

//efficient approach

#include<iostream>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int a, b;
	cin >> a >> b;
	int xr = (a ^ b);
	int count = 0;
	while (xr > 0) {
		count++;
		xr = xr >> 1;
	}
	int sum = 0;
	for (int i = 0; i < count; i++) {

		sum += (1 << i);
	}
	cout << sum << endl;
}