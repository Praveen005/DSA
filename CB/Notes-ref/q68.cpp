//Arrays-Binary Search

#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r", stdin);
	freopen("output.txt", "w" , stdout);
#endif

	int n; cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int m; cin >> m;
	if (binary_search(arr, arr + n, m)) {
		cout << (lower_bound(arr, arr + n, m) - arr) << endl;
	}
	else {
		cout << -1 << endl;
	}
}