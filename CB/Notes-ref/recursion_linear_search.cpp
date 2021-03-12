#include<iostream>
using namespace std;
int lastOcc(int a[], int n, int key) {
	if (n == 0) {
		return -1;
	}
	int i = lastOcc(a + 1, n - 1, key);
	if (i == -1) {
		if (a[0] == key) {
			return 0;
		}
		return -1;
	}
	return i + 1;
}
int linearSearch(int *a, int n, int key) {
	if (n == 0) {
		return - 1;
	}
	if (a[0] == key) {
		return 0;
	}
	int i = linearSearch(a + 1, n - 1, key);
	if (i == -1) {
		return -1;
	}
	return i + 1;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a[] = {1, 2, 13, 17, 4, 5, 6, 17, 6, 17, 10};
	int n = sizeof(a) / sizeof(a[0]);
	cout << linearSearch(a, n, 7) << endl;
	cout << lastOcc(a, n, 7) << endl;

}
