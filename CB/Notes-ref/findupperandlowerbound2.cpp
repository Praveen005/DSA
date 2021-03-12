#include<iostream>
using namespace std;
int lowerbound(int* a , int n, int p) {
	int s = 0;
	int e = n - 1;
	int ans = -1;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (a[mid] == p) {
			ans = mid;
			e = mid - 1;
		}
		else if (a[mid] > p) {
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}

	return ans;
}



int upperbound(int a[] , int n, int p) {
	int s = 0;
	int e = n - 1;
	int ans = -1;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (a[mid] == p) {
			ans = mid;
			s = mid + 1;
		}
		else if (a[mid] > p) {
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}

	return ans;



}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif

	// we have to find the lower and upper bound of occurance of a particular query
	//in an array using Binary Search.

	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int p;
		cin >> p;
		int a1 = lowerbound(a, n, p);
		int a2 = upperbound(a, n, p);
		if (a1 == -1) {
			cout << -1 << " " << -1 << endl;
			continue;
		}
		cout << a1 << " " << a2 << endl;
	}

}