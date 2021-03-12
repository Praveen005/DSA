//binary search revision
#include<iostream>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 55};
	int n = sizeof(a) / sizeof(a[0]);
//	cout << n << endl;
	int i = 0;
	int j = n - 1;
	int key;
	cin >> key;
	while (i <= j) {
		int mid = (i + j) / 2;
		//	cout << "mid =" << mid << endl;
		if (a[mid] == key) {
			cout << mid << endl;
			break;
		}
		else if (a[mid] > key) {
			j = mid - 1;
		}
		else {
			i = mid + 1;
		}

	}
}