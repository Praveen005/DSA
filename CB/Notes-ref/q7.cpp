// printing all subarray for  a given subarray // revision
#include<iostream>
using namespace std;
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
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			for (int k = i; k <= j; k++) {
				cout << a[k] << " ";
			}
			cout << endl;
		}
	}
}