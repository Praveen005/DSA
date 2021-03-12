//revision
#include<iostream>
#include<climits>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif
	//cumulative sum approach
	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int cum[n];
	cum[0] = a[0];
	for (int i = 1; i < n; i++) {
		cum[i] = cum[i - 1] + a[i];
	}
	int maxm = INT_MIN;
	for (int i = 0; i < n; i++) {
		for (int j = i ; j < n; j++) {
			if (i == 0) {
				maxm = max(maxm , cum[j]);
			}
			else {
				maxm = max(maxm , cum[j] - cum[i - 1]);
			}

		}
	}
	cout << maxm << endl;
}