

#include<iostream>
using namespace std;

// this merge function more or less work same as in merge-sort except for the 'count'
int merge(int *a, int s, int e) {
	int mid = (s + e) / 2;
	int i = s;
	int j = mid + 1;
	int k = s;
	int temp[100005];
	int count = 0;
	while (i <= mid && j <= e) {
		if (a[i] <= a[j]) {
			temp[k++] = a[i++];

		}
		else {
			temp[k++] = a[j];
			count += (mid - i + 1);
			j++;
		}
	}
	while (i <= mid) {
		temp[k++] = a[i++];
	}
	while (j <= e) {
		temp[k++] = a[j++];
	}
	for ( i = s; i < k; i++) {
		a[i] = temp[i];
	}
	return count;
}
int func(int *a, int s, int e) {
	//if there is no element or just one element in array then return 0
	if (s >= e) {
		return 0;
	}
	int mid = (s + e) / 2;

	int x = func(a, s, mid);         // x: number of inversions in first half of the array
	int y = func(a, mid + 1, e);	 // y: number of inversions in 2nd half of the array

	int z = merge(a, s, e);		 // z: number of cross inversions [ b/w 1st and 2nd half of the array ]
	return x + y + z;

}
int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif




	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int a[100005];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int s = 0, e = n - 1;
		cout << func(a, s, e) << endl;
	}
}