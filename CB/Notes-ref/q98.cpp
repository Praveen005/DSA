// optimised approach to find the prime factorization of the given number
// #include<iostream>
// using namespace std;
// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// 	int n; cin >> n;

// 	while (n % 2 == 0) {
// 		cout << 2 << " ";
// 		n = n / 2;
// 	}
// 	//cout << n << endl;
// 	for (int i = 3; i * i <= n; i += 2) {
// 		while (n % i == 0) {
// 			cout << i << " ";
// 			n = n / i;
// 		}

// 	}
// 	if (n != 1)
// 		cout << n << endl;
// }



#include<iostream>
#include<vector>
using namespace std;
void printPrimes(int n) {
	vector<pair<int, int> >factors;
	int cnt;
	for (int i = 2; i * i <= n; i++) {
		cnt = 0;
		while (n % i == 0) {
			cnt++;
			n = n / i;
		}
		factors.push_back(make_pair(i, cnt));
	}
	if (n != 1) {
		factors.push_back(make_pair(n, 1));
	}
	for (auto p : factors) {
		cout << p.first << "^" << p.second << endl;
	}
	return;

}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n; cin >> n;
	printPrimes(n);
	return 0;



}