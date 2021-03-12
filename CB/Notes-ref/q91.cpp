// getting into principle of inclusion and exclusion
#include<iostream>
#include<cstring>
using namespace std;
#define ll long long
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w", stdout);
#endif
	// we have to find the number of number between 1 and n which is divided by
	// any prime number between 1 to 20
	int t;
	cin >> t;
	int primes[] = {2, 3, 5, 7, 11, 13, 17, 19}; // 8
	while (t--) {
		ll n;
		cin >> n;
		int noOfSubsets = (1 << 8) - 1;
		int ans = 0;
		for (ll i = 1 ; i <= noOfSubsets; i++) {
			ll no = i;
			ll denom = 1ll;
			int setBits = __builtin_popcount(i);
			int j = 0;
			while (no > 0) {
				if ((no & 1) > 0) {
					denom *= primes[j];
				}
				no = no >> 1;
				j++;
			}
			if (setBits & 1) {
				ans += n / denom;
			}
			else {
				ans -= n / denom;
			}
		}
		cout << ans << endl;
	}
}



