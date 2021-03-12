//revising prime sieve
#include<iostream>
using namespace std;
#define ll long long
void prime_sieve(int a[]) {
	a[0] = a[1] = 0;
	a[2] = 1;

	for (ll i = 3; i <= 1000000; i += 2) {

		a[i] = 1;
	}
	for (ll i = 3; i <= 1000000; i += 2) {
		if (a[i] == 1) {
			for (ll j = i * i; j <= 1000000; j += i) {
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

// 	#ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	int n;
	cin >> n;
	int a[1000000] = {0};
	prime_sieve(a);
	for (int i = 0; i < n; i++) {
		if (a[i] == 1) {
			cout << i << " ";
		}
	}

}