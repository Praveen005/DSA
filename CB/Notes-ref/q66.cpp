//hackerBlocks Painter's Partition Problem
#include<iostream>
#include<climits>
using namespace std;
#define ll long long

bool validTime(ll * a , int n, int k, ll mid) {
	ll count = 0; ll i;
	for ( i = 1; ; i++) {

		ll val = 0, cur_mid = mid;
		while (cur_mid >= a[count] && count < n) {
			ll z = val += a[count];
			cur_mid = mid - z;
			count++;
		}
		if (count == n || i > k) {
			break;
		}
	}

	if (i > k) {
		return false;
	}
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int k;		// k is no of painters
	cin >> k;
	int n; cin >> n; // no of boards

	ll a[n];
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll s = INT_MIN, e = 0, mid;
	// ll s , e , mid;
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		s = max(s, a[i]);
		e = e + a[i];
	}
	while (s <= e) {
		ll mid = (s + e) / 2;

		bool check = validTime( a , n, k, mid);
		if (check) {

			ans = mid;

			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}
	cout << ans << endl;

}