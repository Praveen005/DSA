//writting bubble sort using comparator function
#include<iostream>
#include<algorithm>
using namespace std;
bool compare(int a, int b) {
	return a > b;
}

void bubbleSort(int *a , int n , bool (&cmp)(int a, int b)) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 ; j++) {
			if (cmp(a[j] , a[j + 1])) {
				swap(a[j], a[j + 1]);
			}
		}
	}

}


int main() {
	int a[] = {1, 5, -355, 8, 6, -10};
	int n = sizeof(a) / sizeof(int);
	bubbleSort(a, n, compare);
	for (int i = 0; i < n; i++) {
		cout << a[i] << ",";
	}
}
