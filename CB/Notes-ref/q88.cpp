#include<iostream>
using namespace std;
#define ll long long
//my aim is to find no of numbers less than n which is divided by any of the primes[]
//we will use inclusion-exclusion principle
//get all the possible combinations of the elements in prime[]
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w", stdout);
#endif
	int n = 9;
	ll t; cin >> t;
	ll prime[8] = {2, 3, 5, 7, 11, 13, 17, 19};
	while (t--) {
		ll n;
		ll ans = 0;
		cin >> n;
		ll comb = (1 << 8) - 1;
		for (ll i = 1; i <= comb; i++) {
			ll str = 1ll;
			ll no = i;

			for (ll j = 0; j < 8; j++) {
				if (no & (1 << j)) {
					str = (str * prime[j]);
				}
			}
			if (__builtin_popcount(i) % 2)
				ans = ans + (n / str);
			else {
				ans -= (n / str);
			}

		}
		cout << ans << endl;

	}
}