#include <iostream>
#include<algorithm>
using namespace std;
int keySearch(int a[] , int n , int key) {
	int s = 0;
	int e = n - 1;
	int ans = -1; //index -1 means item not found
	while (s <= e) {
		int mid = (s + e) / 2;
		//there r 2 sorted array  4,5  &  1,2,3
		//copy me help rahul samajh lo :)
		if (a[mid] == key) {

			return mid;
		}

		else if (a[mid] >= a[0]) {
			if (key < a[mid] && key >= a[0]) {
				s = 0;
				e = mid - 1;
			}
			else {
				s = mid + 1;
			}
		}
		else {
			if (key > a[mid]) {
				s = mid + 1;
				e = n - 1;
			}
			else {
				e = mid - 1;
			}

		}
	}
	return ans;

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w", stdout);
#endif

	//a sorted array has been rotated by an idiot to create two monotonic array within one now we
	//HAVE TO search for the key provided.
	//BINARY SEARCH WILL BE USED.

	int n ; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int key; cin >> key;
	cout << keySearch(a, n, key) << endl;


}
