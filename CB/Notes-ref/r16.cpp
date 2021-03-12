// Prime Factorization
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>primeSieve(int *p , int n) {
	p[0] = p[1] = 0;
	p[2] = 1;
	for (int i = 3; i <= n; i += 2) {
		p[i] = 1;
	}
	for (int i = 3; i <= n; i += 2) {
		if (p[i] == 1) {
			for (int j = i * i; j <= n; j += i) {
				p[j] = 0;
			}
		}
	}
	vector<int> primes;
	primes.push_back(2);
	for (int i = 3; i <= n; i += 2) {
		if (p[i] == 1) {
			primes.push_back(i);
		}
	}
	return primes;
}

vector<int>factorize(int no , vector<int>&primes) {
	vector<int> factor;
	factor.clear();

	int p = primes[0];
	for (int i = 0; primes[i]*primes[i] <= no; i++) {
		int j = primes[i];
		while (no % j == 0) {
			no = no / j;
			//cout << no << endl;
			factor.push_back(primes[i]);

		}
	}
	if (no != 1) {
		factor.push_back(no);
	}
	return factor;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int p[10000] = {0};
	vector<int>primes = primeSieve(p, 1000);
	int t; cin >> t;
	while (t--) {
		int  no;
		cin >> no;
		vector<int>factor = factorize(no, primes);

		for (auto f : factor) {
			cout << f << " ";
		}
		cout << endl;
	}
}