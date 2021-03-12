// OR subarray
//ghisa pita tarika
#include<iostream>
using namespace std;
#define ll long long


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int ar[100009];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	ll sum = 0;
	int a;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			a = 0;
			for (int k = i; k <= j; k++) {

				a = (a | ar[k]);

			}

			sum += a;

		}
	}
	cout << sum << endl;


}

