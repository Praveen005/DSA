//insertion sort

#include<iostream>
using namespace std;
void sort(int *a, int n) {
	for (int i = 1; i < n; i++) {
		int e = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > e) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = e;
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int a[100];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, n);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}

}
