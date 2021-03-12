#include<iostream>
using namespace std;
//ek tarika
// void bubble_sort(int* a, int n) {
// 	if (n == 1) {
// 		return;
// 	}
// 	for (int j = 0; j < n - 1; j++) {
// 		if (a[j] > a[j + 1]) {
// 			swap(a[j], a[j + 1]);
// 		}
// 	}
// 	bubble_sort(a, n - 1);
// }

void bubble_sort_recursive(int* a, int j, int n) {
	if (n == 1) {
		return;
	}
	if (j == n - 1) {
		return bubble_sort_recursive(a, 0, n - 1);
	}
	if ( a[j] > a[j + 1] ) {
		swap(a[j], a[j + 1]);
	}
	return bubble_sort_recursive(a, j + 1, n);

}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a[] = {5, 3, -1, 7, 4, 9};
	int n = sizeof(a) / sizeof(a[0]);
	// bubble_sort(a, n);
	bubble_sort_recursive(a, 0, n);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}