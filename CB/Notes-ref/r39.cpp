#include<iostream>
using namespace std;
#define ll long long
const ll N = 100005;
//#define ll long long

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll t; cin >> t;
	while (t--) {
		ll a[N];
		ll r[N] = {0};
		//r[0]=0;
		ll n; cin >> n;
		for (ll i = 0; i < n; i++) {
			cin >> a[i];

		}
		// we will form one another array to store prefix sum
		// to get the sum of different array
		//  (b-a)%N ==0   means   b%n== a%n
		r[0] = 1;
		ll sum = 0;
		for (ll i = 0; i < n; i++) {
			sum += a[i];
			sum = sum % n;
			// to deal with the case when remainder i.e.  sum%n  is negative
			sum = (sum + n) % n;
			r[sum]++;
		}
		sum = 0;
		for (ll i = 0; i < n; i++) {
			ll k = r[i];
			sum += ((k * (k - 1)) / 2);
		}
		cout << sum << endl;
	}
}