/*
	https://hack.codingblocks.com/app/practice/1/736/problem
*/

// quick sort ALgorithm

#include<iostream>
using namespace std;
int partition(int a[], int s, int e) {
	int i = s - 1;
	int j = s;
	int pivot = a[e];
	for (; j < e; j++) {
		if (a[j] <= pivot) {
			i++;
			swap(a[j], a[i]);
		}
	}
	swap(a[i + 1], a[j]);
	return i + 1;
}
void quickSort(int a[], int s, int e) {
	if (s >= e) {
		return ;
	}
	//p here represents the index of pivot element
	int p = partition(a, s, e);
	//1st part of the array
	quickSort(a, s, p - 1);
	//2nd part of the array
	quickSort(a, p + 1, e);

}
int main() {
/*
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
*/
	int n; cin >> n;
	int a[200005];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int s = 0, e = n - 1;
	quickSort(a, s, e);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}

}
