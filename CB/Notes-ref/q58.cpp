//prime seive
#include<iostream>

using namespace std;
#define ll long long
bool prime_seive(ll a[]) {
	//only multiples of of 3 can be prime
	for (ll i = 3; i <= 1000000000; i += 2) {
		a[i] = 1;
	}
	for (ll i = 3 ; i <= 1000000000; i += 2) {

		if (a[i] == 1) {

			for (ll j = i * i;  j <= 1000000000; j += i ) {
				a[j] = 0;

			}
		}
	}
	a[2] = 1;
	a[0] = a[1] = 0;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll a[1000000000] = {0};


	prime_seive(a);
	ll itr;
	cin >> itr;
	while (itr > 0) {
		ll n1, n2;
		cin >> n1 >> n2;
		ll count = 0;
		for (ll i = n1; i <= n2; i++) {
			if (a[i] == 1) {
				cout << i << endl;
				count++;
			}
		}
		cout << endl;
		itr--;
	}

} n