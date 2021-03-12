#include <iostream>
#include<algorithm>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w", stdout);
#endif
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int s = 0; int e = n - 1;
	int ans = -1;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (a[mid] > a[mid - 1] && a[mid] > a[mid + 1]) {
			ans = mid;
			break;
			//	s = mid + 1;
		}
		else if (a[mid] >= a[0]) {
			s = mid + 1;

		}
		else {
			e = mid - 1;
		}
	}

	cout << ans << endl;
}
