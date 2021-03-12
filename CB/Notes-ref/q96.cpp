// number theory starts
//Prime Visits
#include<iostream>
using namespace std;
#define ll long long
void primes(int a[]) {
	a[1] = a[0] = 0;
	a[2] = 1;
	for (int i = 3 ; i <= 1000000; i += 2) {
		a[i] = 1;
	}
	for (ll i = 3; i <= 1000000; i += 2) {
		if (a[i] == 1) {
			for (ll j = i * i ; j <= 1000000; j += i) {
				a[j] = 0;
			}
		}
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t; cin >> t;
	int a[1000000] = {0};
	primes(a);
	while (t--) {
		int n1, n2;
		cin >> n1 >> n2;
		int count = 0;
		for (int i = n1; i <= n2; i++) {
			if (a[i] == 1) {
				count++;
			}
		}
		cout << count << endl;
	}

}