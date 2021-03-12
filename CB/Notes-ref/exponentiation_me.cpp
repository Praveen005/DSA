#include<iostream>
using namespace std;
#define ll long long
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w", stdout);
#endif
	ll t;
	cin >> t;
	ll prime[8] = {2, 3, 5, 7, 11, 13, 17, 19};
	while (t--) {
		ll n; cin >> n;
		ll subsets;
		ll ans = 0;
		//ll denom = 1ll;
		ll k = (1 << 8) - 1 ;
		for (ll i = 1; i <= k; i++) {

			ll no = i;
			int j = 0;
			ll denom = 1ll;
			//this for loop tries out all possible combinations
			for (ll j = 0; j <= 7; j++) {
				if (i & (1 << j)) {
					denom = denom * prime[j];

				}
			}

			subsets = __builtin_popcount(i);
			if (subsets & 1) {
				ans = ans + (n / denom);

			}
			else {
				ans -= (n / denom);
			}

		}
		cout << ans << endl;
	}

}