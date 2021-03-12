//prime generator
#include<iostream>
using namespace std;
#define ll long long
void primeGenerator(ll* a) {
	a[0] = a[1] = 0;
	a[2] = 1;
	for (ll i = 3 ; i <= 1000000000; i += 2 ) {
		a[i] = 1;
	}
	// value 1 shows that the number is still not visited may or may not be prime.
	//value 0 shows visited and not prime
	for (ll i = 3; i <= 1000000000; i += 2) {
		if (a[i] == 1) {
			for (ll j = i * i; j <= 1000000000; j += j) {
				a[j] = 0;
			}
		}
	}

}




int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll a[1000000000] = {0};
	int t;
	cin >> t;
	while (t--) {


		int n1, n2;
		cin >> n1 >> n2;
		primeGenerator(a);
		for (int i = n1; i <= n2; i++) {
			if (a[i] == 1) {
				cout << i << endl;
			}
		}
		cout << endl;
	}
}