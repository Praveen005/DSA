#include<iostream>
using namespace std;
int decmalToBinary(int n) {
	int ans = 0, p = 1;
	while (n > 0) {
		int last_bit = (n & 1);
		ans += p * last_bit;
		p *= 10;
		n = n >> 1;
	}
	return ans;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w", stdout);
#endif

	int n;
	cin >> n;
	cout << decmalToBinary(n) << endl;


}