// program to find the total number of divisors
// simple problem based on P& C

// didn't use vector because vector abhi padha nahi hai.
#include<iostream>
#include<vector>
using namespace std;
#define ll long long
void primeSeive(int a[]) {
	for (int i = 3; i <= 1000000; i += 2) {
		a[i] = 1;
	}
	for (ll i = 3 ; i <= 1000000; i += 2) {
		if (a[i] == 1) {
			for (ll j = i * i ; j <= 1000000 ; j += i) {
				a[j] = 0;
			}
		}
	}
	a[0] = a[1] = 0;
	a[2] = 1;

}
void divN(int n , int prime[]) {
	int i = 0;
	int p = prime[i];
	int ans = 1;
	while (p * p <= n) {
		int cnt = 0;
		while (n % p == 0) {
			cnt++;
			n = n / p;
		}
		ans *= (cnt + 1);
		i++;
		p = prime[i];
	}
	cout << ans << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int N = 1000000;
	int a[N] = {0};
	primeSeive(a);
	int prime[1000000];
	int count = 0;
	for (int i = 0; i <= 1000000 ; i++) {
		if (a[i] == 1) {
			prime[count] = i;
			count++;
		}
	}

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		divN(n, prime);
	}
}