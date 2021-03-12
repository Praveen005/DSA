/*

Input : arr[] = { 1, 2, 2, 3, 5 }, M = 4
L = 1, R = 2
L = 1, R = 5
L = 3, R = 6
L = 9, R = 30
Output :
2
5
4
5

*/

#include<iostream>
#include<bitset>
using namespace std;
#define MAX 1000
void check_subset_sum(int l, int r, bitset<MAX>bit) {
	int count = 0;
	for (int i = l; i <= r; i++) {
		if (bit[i] == 1) {
			count++;
		}
	}
	cout << count << endl;
}
void bit_arrangement(int* a, bitset<MAX>&bit, int n) {
	bit.reset();
	bit[0] = 1;
	for (int i = 0; i < n; i++) {
		bit |= (bit << a[i]);
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a[] = {1, 2, 2, 3, 5};
	int n = sizeof(a) / sizeof(a[0]);
	bitset<MAX>bit;
	int m = 4;
	while (m--) {
		int l, r;
		cin >> l >> r;
		bit_arrangement(a, bit, n);
		check_subset_sum(l, r, bit);
	}
}