#include<iostream>
using namespace std;
//bool check()
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif
	int n; cin >> n; int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int k; cin >> k;
	//question asks us to find the k = k = 2
	// so k could either be on the first part of the sequence or the other
	int s = 0; int e = n - 1;
	int ans = -1;
	while (s <= e) {
		int mid = (s + e) / 2;
		//bool isValid=
		if (a[mid] == k) {
			ans = mid;
			break;
		}
		else if (a[mid] >= a[0]) {
			// check if k lies there or not
			if (k >= a[0] && k < a[mid]) {
				s = a[0];
				e = mid - 1;
			}
			else {
				s = mid + 1;
			}
		}
		else {
			if (k <= a[n - 1] && k > a[mid]) {
				s = mid + 1;

			}
			else {
				e = mid - 1;
			}
		}
	}
	cout << ans << endl;
}