//first and last occurance of elment in an array
#include<iostream>
using namespace std;
void firstOccurance(int * a, int n, int key) {
	int s = 0;
	int e = n - 1;
	int ans = -1;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (a[mid] == key) {
			ans = mid;
			e = mid - 1;
		}
		else if (a[mid] < key) {
			s = mid + 1;

		}
		else {
			e = mid - 1;
		}
	}
	cout << "first Occurance " << ans << endl;
	return;
}
void lastOccurance(int * a, int n, int key) {
	int s = 0;
	int e = n - 1;
	int ans = -1;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (a[mid] == key) {
			ans = mid;
			s = mid + 1;
		}
		else if (a[mid] < key) {
			s = mid + 1;

		}
		else {
			e = mid - 1;
		}
	}
	cout << "first Occurance " << ans << endl;
	return;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int key;
	cin >> key;
	firstOccurance(a, n, key);
	lastOccurance(a, n, key);
}