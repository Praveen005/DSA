#include<iostream>
#include<climits>
using namespace std;
#define ll long long
ll check(ll a[], ll n, ll k, ll t , ll min_time) {
	ll sum = 0;
	ll count = 1;
	for (ll i = 0; i < n; i++) {
		if (sum + (a[i] * t) > min_time) {
			count++;
			sum = a[i] * t;
		}
		else {
			sum += a[i] * t;
		}
	}
	if (count <= k) {
		return true;
	}
	else {
		return false;
	}
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif
	ll n, k, t;
	//n -size of array i.e no of boards
	//k - no of pallers
	//T - time taken by each paller to pall single unit of board

	cin >> n >> k >> t;
	ll a[n];
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}


//	ll sum = 0;
	ll s = INT_MIN;
	ll e = 0;
	for (ll i = 0; i < n; i++) {
		s = max(s, a[i]);
		e += a[i];
	}
	s = s * t;
	e = e * t;
	//cout << s << "  " << e << endl;
	ll ans = 0;
	while (s <= e) {
		ll mid = (s + e) / 2;

		bool ifValid = check(a, n, k, t, mid);
		if (ifValid) {
			ans = mid;
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}


	cout << ans % 10000003 << endl;
}