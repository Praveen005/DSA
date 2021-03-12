#include<iostream>
#include<algorithm>
using namespace std;
bool check(int a[] , int n, int c , int min_gap) {
	int count = 1;
	int last_placed = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] - last_placed >= min_gap) {
			count++;
			last_placed = a[i];
			if (count == c) {
				return true;
			}
		}
	}
	return false;
}
int minGap(int a[], int n, int c) {
	//yahan hamlog gap ko maximize karna hai
	int s = 0;
	int e = (a[n - 1] - a[0]);
	int ans = 0;
	while (s <= e) {
		int mid = (s + e) / 2;
		bool isValid = check(a, n, c, mid);
		if (isValid) {
			ans = mid;
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
	return ans;
	//cout << ans << endl;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif

	int n, c;
	cin >> n >> c;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	// array sorted hona jaruri hai kyun ki phir bool
	//function ka if condition valid nahi rah jaayega
	sort(a, a + n);
	cout << minGap(a, n, c) << endl;
	//minGap(a, n, c);
}