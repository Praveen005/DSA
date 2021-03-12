#include<iostream>
using namespace std;
#define ll long long
const int N = 10000;
const ll M = 100000000003 ;
ll func1(ll a , ll b) {
	ll res = 0;
	a = a % M;
	while (b) {
		if (b & 1) {
			res = (res + a) % M;
		}

		a = (a * 2) % M;

		b = b / 2;
	}
	return res;
}
void func(ll *ar) {
	ll a;
	ll j = (ar[2] - ar[1]);
	ll k = (ar[1] - ar[0]);

	if (j != 0   && k != 0) {
		a = j / k;
	}
	else {
		a = 0;
	}
	ll b = (ar[1] - (a * ar[0]));
	ll s = func1(a, ar[5]);
	ll p = ( s + (b % M) % M) ;
	cout << p << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll a[M];
	while (cin >> a[0]) {
		for (int i = 1; i < 6; i++) {
			cin >> a[i];
		}
		func(a);
	}
}






