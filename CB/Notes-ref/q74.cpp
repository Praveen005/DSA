// //revision
// printing all subarrays
#include<iostream>
#include<climits>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif
	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int maxm = INT_MIN;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int sum = 0;
			for (int k = i; k <= j; k++) {
				cout << a[k] << " ";
				sum += a[k];
			}
			maxm = max(maxm , sum);
			cout << endl;
		}
	}

	cout << maxm << endl;
}