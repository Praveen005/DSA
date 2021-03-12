//help rahul
//searching key in a rotated array

#include<iostream>
using namespace std;
int findingKey(int *a , int n , int key) {
	int s = 0; int e = n - 1;
	while (s <= e) {
		int mid = (e + s) / 2;
		if (a[mid] == key) {
			return mid;
		}
		if (a[s] <= a[mid]) {
			//means left increasing part has mid index
			//yaha bhi 2 cases 1st half or second
			if (a[s] <= key && key < a[mid]) {
				e = mid - 1;
			}
			else {
				s = mid + 1;
			}

		}
		else if (key > a[mid] and key <= a[e]) {
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
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
	cout << findingKey(a, n, key) << endl;

}