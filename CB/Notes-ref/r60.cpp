

#include<iostream>
#include<cstring>
using namespace std;
int GoForOuting(int n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	int ans;
	ans = GoForOuting(n - 1) + (n - 1) * GoForOuting(n - 2);
	return ans;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	cout << GoForOuting(n) << endl;

}