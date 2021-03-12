//insertion sort revision
//har program ko ek baar dry run kar ke dekh liya karo
#include <iostream>
using namespace std;
void insertionSort(int *a , int n) {
	//selection sort me min ko khoj kar pahle laaya jata hai :)

	for (int i = 1; i < n; i++) {
		int j = i;
		int e = a[j];
		while (j > 0 && a[j - 1] > e) {
			a[j] = a[j - 1];
			j--;
		}
		a[j] = e;
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
	insertionSort(a, n);

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}

}

// :)  worked in first attempt