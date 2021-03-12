#include<iostream>
using namespace std;
void merge(int * a, int s, int e) {
	int mid = (s + e) / 2;
	int i = s;
	int j = mid + 1;
	int temp[1000];
	int k = s;
	while (i <= mid && j <= e) {
		if (a[i] < a[j]) {
			temp[k++] = a[i++];
		}
		else {
			temp[k++] = a[j++];
		}
	}
	while (i <= mid) {
		temp[k++] = a[i++];
	}
	while (j <= e) {
		temp[k++] = a[j++];
	}
	for (int i = 0; i < k; i++) {
		a[i] = temp[i];
	}

}
void mergeSort(int a[], int s, int e) {
	if (s >= e) {
		return;
	}
	// splittiing into halves
	int mid = (s + e) / 2;
	mergeSort(a, s, mid);
	mergeSort(a, mid + 1, e);
	// merge

	merge(a, s, e);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a[] = {2, 3, 1, 5, 8, -7};
	int n = sizeof(a) / sizeof(a[0]);
	mergeSort(a, 0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}
