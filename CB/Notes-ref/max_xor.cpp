// max xor problem
#include<iostream>
using namespace std;
#define ll long long


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll a, b;
	cin >> a >> b;
	ll  c;
	c = (a ^ b);
	ll count = 0;
	while (c > 0) {
		count++;
		c = (c >> 1);
	}
//	cout << count << endl;
	ll sum = 0;
	for (ll i = 0; i < count; i++) {
		sum += (1ll << i);
	}
	cout << sum << endl;

}

