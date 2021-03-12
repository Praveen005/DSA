//kth root
//binary search
#include<iostream>
#include<valarray>
#include<climits>
using namespace std;
#define ll long long
bool check( ll mid, ll n, int k) {
	//cout << "mid = " << mid << endl;
	if (pow(mid , k) <= n) {
		return true;
	}
	return false;
}
ll maxnum(ll n, int k) {
	int s = 1;
	ll e = 1000000000000000;
//	cout << "e " << e << endl;
	int ans = 0;
	while (s <= e) {
		ll mid = (s + e) / 2;
		//	cout << "mid = " << mid << endl;
		bool isValid = check(mid, n, k);
		if (isValid) {
			ans = mid;
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

	int t; cin >> t;
	while (t--) {
		ll n; int k;
		cin >> n >> k;
		cout << maxnum( n,  k) << endl;

	}
	//cout << maxnum( n,  k) << endl;
}