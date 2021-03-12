//counting number of  divisors of a number using prime sieve
#include<iostream>
#include<vector>
using namespace std;
#define ll long long
#define N 1000
vector<int>primeSieve(int *a) {
	a[0] = a[1] = 0;
	a[2] = 1;
	for (int i = 3; i <= N; i += 2) {
		a[i] = 1;
	}
	for (ll i = 3; i <= N; i += 2) {
		if (a[i] == 1) {
			for (ll j = i * i; j <= N ; j += i ) {
				a[j] = 0;
			}
		}
	}
	std::vector<int> primes;
	for (int i = 0; i <= N; i++) {
		if (a[i] == 1) {
			primes.push_back(i);
		}
	}
	return primes;
}

void divisors(int n, vector<int>primes) {
	vector<pair<int, int>>div;
	for (int i = 0; primes[i]*primes[i] <= n; i++) {
		if (n % primes[i] == 0) {
			int cnt = 0;
			while (n % primes[i] == 0) {
				cnt++;
				n = n / primes[i];
			}
			div.push_back(make_pair(primes[i], cnt));
		}
	}
	if (n != 1) {
		div.push_back(make_pair(n, 1));
	}
	cout << div.size() << endl;
	for (int i = 0; i < div.size(); i++) {
		+
		cout << div[i].first << " " << div[i].second << endl;
	}
	//getting total number of divisors
	int prod = 1;
	for (int i = 0; i < div.size(); i++) {
		prod *= (div[i].second + 1);
	}
	cout << prod << endl;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// n is the number whose number of divisor is to be found out
	int n; cin >> n;

	int a[N] = {0};
	vector<int>primes = primeSieve(a);
	divisors(n, primes);
}

// done :)