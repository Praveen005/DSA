//PRATA SPOJ
#include <iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
bool check(int arr[], int prata, int worker, int mid) {
	int count = 0;
	// int sum = 0;
	// int fact = 1;
	for (int i = 0; i < worker; i++) {
		int sum = 0;
		int fact = 1;
		while (sum + (fact * arr[i]) <= mid) {
			count++;
			sum += fact * arr[i];
			fact++;
		}
		// if (sum + (fact * arr[i]) > mid) {
		// 	sum = 0;
		// 	fact = 1;
		// }
	}
	if (count >= prata) {
		return true;
	}
	return false;
}
void minTime(int arr[], int prata, int worker, int s, int e) {
	int ans = 0;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (check(arr, prata, worker, mid)) {
			ans = mid;
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}
	cout << ans << endl;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "worker", stdout);
#endif
	int t; cin >> t;
	while (t--) {
		int prata; cin >> prata;
		int worker; cin >> worker;
		int arr[10000];
		int s = 0, e = INT_MIN;
		for (int i = 0; i < worker; i++) {
			cin >> arr[i];
			e = max(e, arr[i]);
		}
		e = e * ((prata / 2 * (prata + 1)));
		minTime(arr, prata, worker, s, e);
	}
}
