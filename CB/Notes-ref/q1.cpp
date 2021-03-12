//bubble sort revision
#include<iostream>
using namespace std;
void bubbleSort(int *a , int n) {
	//bubble sort me continous swapping hota hai
	for (int i = 0; i < n - 1; i++) {
		for (int j = 1; j < n - i; j++) {
			if (a[j - 1] > a[j]) {
				swap(a[j - 1], a[j]);
			}
		}
	}
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	bubbleSort(a, n);

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}

}

//it worked  :)