//SUM OF ALL THE SUBARRAY OF A 2D ARRAY
//will discuss all the approaches;
#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);

	freopen("output.txt" , "w", stdout);
#endif
	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int digit[10] = {0};
	for (int i = 0; i < n; i++) {
		int* val = new int(0);
		*val = a[i];
		digit[*val]++;
		delete val;
	}
	for (int i = 1; i < 10; i++) {
		digit[i] += digit[i - 1];
	}
	int p[n];
	for (int i = 0; i < n; i++) {
		p[digit[a[i]] - 1] = a[i];
		digit[a[i]]--;
	}
	for (int i = 0; i < n; i++) {
		cout << p[i] << " ";
	}
}