/*
1<=T<=10
1<=N<=10^5
|ai|<=10^9
*/
#include<iostream>
#include<cstring>
using namespace std;
#define ll long long
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t; cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[100005];
		int freq[100005];
		ll sum = 0;
		memset(freq, 0, sizeof(freq));
		freq[0] = 1;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
			sum = sum % n;
			sum = (sum + n) % n;
			freq[sum] = freq[sum] + 1;
		}
		ll ans = 0;
		for (int i = 0; i <= n; i++) {
			ll m = freq[i];
			if (freq[i] > 1) {
				ans += (m * (m - 1)) / 2;
			}
		}
		cout << ans << endl;
	}
}