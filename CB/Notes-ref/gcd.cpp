// #include<iostream>
// using namespace std;
// #define int long long
// void gcd(int a, int b) {
// 	if (b == 0) {
// 		cout << a << endl;
// 		return;
// 	}
// 	gcd(b, a % b);
// }
// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// 	int a, b;
// 	cin >> a >> b;
// 	gcd(a, b);

// }

// more concise


#include<iostream>
using namespace std;
#define ll long long
int gcd(int a, int b) {
	return (b == 0) ? a : gcd(b, a % b);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a, b;
	cin >> a >> b;
	cout << gcd(a, b);

}