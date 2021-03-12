//1st meathod
#include<iostream>
using namespace std;
int countSetBit(int n) {
	int ans = 0;
	while (n > 0) {
		ans += (n & 1);
		//	cout << ans << endl;
		n = (n >> 1);
	}
	return ans;
}
int countBitFast(int n) {
	int ans = 0;
	while (n > 0) {
		n = n & (n - 1);
		ans++;
	}
	return ans;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt"  , "w" , stdout);
#endif
	int n;
	cin >> n;
	cout << countSetBit(n) << endl;
	cout << countBitFast(n) << endl;
	cout << __builtin_popcount(n) << endl;;

}