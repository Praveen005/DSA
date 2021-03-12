// exponentiation
// iterative approach
//modular exponentiation: iterative and recursive approach

//  #1
// #include<iostream>
// using namespace std;
// void power(int a, int b) {
// 	int res = 1;
// 	int x = 3;
// 	while (b > 0) {
// 		if (b & 1) {
// 			res *= x;
// 		}
// 		b = b >> 1;
// 		x = x * x;
// 	}
// 	cout << res << endl;
// }
// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// 	int a = 3;
// 	int b = 5;
// 	power(a, b); // a^b
// }

//  #2
// ref : modular exponentiation / geekforgeeks
// #include<iostream>
// using namespace std;
// void power(int a, int b, int m) {
// 	int x = a;
// 	int res = 1;
// 	while (b > 0) {
// 		if (b & 1) {
// 			res = (res * x) % m;
// 		}
// 		x = (x * x) % m;
// 		b = b >> 1;
// 	}
// 	cout << res << endl;
// }
// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// 	int a, b, m;
// 	cin >> a >> b >> m;
// 	power(a, b, m);
// }


// recursive approach

#include<iostream>
using namespace std;
int power(int a, int b, int m) {
	long y;
	if (a == 0) {

		return 0;
	}
	if (b == 0) {

		return 1;
	}
	if (b % 2) {
		y = a % m;
		y = (y * power(a, b - 1, m)) % m;
	}
	else {
		y = power(a, b / 2, m);
		y = (y * y) % m;
	}

	return (y + m) % m;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a, b, m;
	cin >> a >> b >> m;
	cout << power(a, b, m);
}