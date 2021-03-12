// power  O(nlogn)   or  exponentiation using bitmasking;

#include<iostream>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int a, b;
	//a is base  & b is exponent
	cin >> a >> b;
	int ans = 1;
	while (b > 0) {
		if (b & 1) {

			ans *= a;
		}
		a = a * a;
		b = b >> 1;
	}
	cout << ans << endl;

}