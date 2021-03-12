#include<iostream>
#include<vector>
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
	vector<int>primes;
	for (int i = 0; i <= n; i++) {
		if (p[i] == 1) {
			primes.push_back(i);
		}
	}
	return primes;
}

vector<pair<int, int>>factorize(int no, vector<int>primes) {
	vector<pair<int, int>>factors;
	factors.clear();
	int count = 0, k = 1;
	for (int i = 0; primes[i]*primes[i] <= no; i++) {
		int j = primes[i];
		if (no % j == 0) {


			while (no % j == 0) {
				k++;
				no = no / j;
			}

			factors.push_back(make_pair(j, k - 1));
			count++;
		}

	}
	if (no != 1) {
		factors.push_back(make_pair(no, 1));
	}
	return factors;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int p[100000] = {0};
	int n;
	cin >> n;
	primeSieve(p, n);


	vector<int> primes = primeSieve(p, n);

	int t; cin >> t;
	while (t--) {
		int no; cin >> no;
		vector<pair<int, int>>factors = factorize(no, primes);
		for (int i = 0; i < factors.size(); i++) {
			cout << factors[i].first << " " << factors[i].second << endl;
		}
	}
}