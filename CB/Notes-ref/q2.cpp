//selection sort revision

#include<iostream>
using namespace std;
void selectionSort(int *a , int n) {
	//selection sort me min ko khoj kar pahle laaya jata hai :)

	for (int i = 0; i < n - 1; i++) {
		int j = i + 1;
		int min_so_far = a[i];
		int minIndex = i;
		for (  ; j < n; j++) {
			if (a[j] < min_so_far) {
				min_so_far = a[j];
				minIndex = j;
			}
		}
		swap(a[i], a[minIndex]);
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
	selectionSort(a, n);

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}

}

// :)  worked in first attempt