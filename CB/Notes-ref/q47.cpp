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
	//input first array
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	//input 2nd array
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	//created 3rd array of arbitrary 2*n say 100 to store both integers
	//one thing you can also do is that take 1st array of greater 2*n and then accomodate 2nd into first one
	//baki aapki marzi  :)
	int c[100];

	//now we store both array in 3rd array  i.e.  c[100]
	for (int i = 0; i < 2 * n; i++) {
		if (i < n) {
			c[i] = a[i];
		}
		else {
			c[i] = b[i - n];
		}
	}
	sort(c, c + 2 * n);


	if (2 * n % 2 == 0) {
		cout << c[((2 * n / 2) + (2 * n / 2 + 1)) / 2 - 1];
	}
	else {
		cout << c[((2 * n + 1) / 2) - 1] << endl;
	}


}