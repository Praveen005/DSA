#include<iostream>
using namespace std;
#define ll long long

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w", stdout);
#endif
	int t; cin >> t;
	while (t--) {
		int n;
		ll k;
		cin >> n >> k;
		int a[100005];
		for (int i = 0; i < n; i++) {
			cin >> a[i];

		}
		ll prod; int count = 0;

		for (int i = 0; i < n; i++) {

			prod = 1;
			for (int j = i ; j < n; j++) {
				prod = prod * a[j];
				if (prod < k) {
					count++;
				}
				else {
					break;
				}
			}
		}
		cout << count << endl;
	}
}