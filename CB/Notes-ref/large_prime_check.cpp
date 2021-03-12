#include<iostream>
#include<vector>
#include<bitset>
using namespace std;
#define ll long long
const int n = 10000000;
bitset<10000005>b;
vector<int>primes;
void sieve() {
	b.reset();
	b[0] = b[1] = 0;
	b[2] = 1;
	primes.push_back(2);
	for (int i = 3; i <= n; i += 2) {
		b[i] = 1;
	}
	for (ll i = 3; i <= n; i++) {
		if (b[i] == 1) {
			primes.push_back(i);
			for (ll j = i * i; j <= n; j += i) {
				b[j] = 0;
			}
		}
	}
}
bool isPrime(ll no) {
	if (no <= n) {
		if (b[no] == 1) {
			return true;
		}
		return false;
	}
	else {
		// if you don't typecast primes[i](which is integer) to long long then
		// product of two large integers will overflow and won't change or will be stored as long long
		// unless we typecast it to long long
		for (ll i = 0; primes[i] * (ll)primes[i] <= no; i++) {
			if (no % primes[i] == 0) {
				return false;
			}
		}
	}
	return true;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	sieve();
	ll no; cin >> no;
	if (isPrime(no)) {
		cout << "yes" << endl;
	}
	else {
		cout << " no" << endl;
	}
}