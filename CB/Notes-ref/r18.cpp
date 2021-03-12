// #include<iostream>
// #include<vector>
// using namespace std;
// void printFactors(int n) {
// 	vector<pair<int, int>>factors;
// 	int i = 2;
// 	int c = 0;
// 	while (n % i == 0) {
// 		c++;
// 		n = n / i;
// 	}

// 	factors.push_back(make_pair(i, c));
// 	c = 0;
// 	for (int i = 3; i * i <= n; i += 2) {
// 		while (n % i == 0) {
// 			c++;
// 			n = n / i;
// 		}
// 		if (c > 0)
// 			factors.push_back(make_pair(i, c));
// 		c = 0;
// 	}
// 	for (auto p : factors) {
// 		cout << p.first << "^" << p.second << "+";
// 	}
// }
// int main(int argc, char const *argv[])
// {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

// 	int n; cin >> n;
// 	printFactors(n);
// }


//Q2.
//counting divisors


#include<iostream>
#include<vector>
using namespace std;
vector<pair<int, int>>printFactors(int n) {
	vector<pair<int, int>>factors;
	int i = 2;
	int c = 0;
	while (n % i == 0) {
		c++;
		n = n / i;
	}

	factors.push_back(make_pair(i, c));
	c = 0;
	for (int i = 3; i * i <= n; i += 2) {
		while (n % i == 0) {
			c++;
			n = n / i;
		}
		if (c > 0)
			factors.push_back(make_pair(i, c));
		c = 0;
	}
	for (auto p : factors) {
		cout << p.first << "^" << p.second << "+";
	}

	cout << endl;
	return factors;
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n; cin >> n;
	vector<pair<int, int>>factors = printFactors(n);
	int no_of_divisors = 1;
	for (auto p : factors) {
		no_of_divisors *= p.second + 1;
	}
	cout << no_of_divisors << endl;
	// proper divisor means all the divisors except 1
}