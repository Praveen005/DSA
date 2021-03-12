//EKO problem from spoj
//binary search
//#include<iostream>

//#include<bits/stdc++.h>
#include<iostream>
#include<climits>
using namespace std;
#define ll long long
bool check(ll arr[] , ll n , ll m, ll max_H) {
	ll sum = 0;
	// cout << "mid = " << max_H << endl;
	for (ll i = 0 ; i < n; i++) {
		// 	if (arr[i] < max_H) {
		// 		continue;
		// 	}
		// 	ll l = arr[i] - max_H;
		// 	if (sum + l >= max_H ) {///  here instead of max_H it has to be m
		// 		return true;

		// 	}
		// 	else {
		// 		sum += l;
		// 	}
		// }


		if (arr[i] < max_H) {
			continue;
		}
		else {
			sum += (arr[i] - max_H);
		}

	}
	if (sum >= m) {
		return true;
	}
	return false;
	// if (sum >= m) {
	// 	return true;
	// }
	// return false;

}

ll maxHeight(ll arr[] , ll n, ll m) {
	ll s = 0;
	ll e = INT_MIN;
	for (ll i = 0; i < n; i++) {
		e = max(e, arr[i]);
	}

	ll ans = 0;
	while (s <= e) {
		ll mid = (s + e) / 2;


		bool isValid = check( arr,  n ,  m, mid);
		if (isValid) {
			ans = mid;
			//cout << ans << endl;
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
	return ans;
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r", stdin);
	freopen("output.txt", "w" , stdout);
#endif

	ll n; cin >> n; //no of trees
	ll m; cin >> m; // amount of wood required

	ll arr[n];
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}


	cout << maxHeight(arr, n, m) << endl;

}