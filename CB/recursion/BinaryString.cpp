/*
	problem : count the number of binary strings of length N can be formed , which have no consecutive 1's
*/



#include<iostream>
#include<cstring>
using namespace std;
int binaryStrings(int n) {
	if (n == 0) {
		return 1;
	}
	if (n == 1) {
		return 2;
	}

	int ans = binaryStrings(n - 1) + binaryStrings(n - 2);
	return ans;
}
int main() {
/*
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
*/
	int n;
	cin >> n;
	cout << binaryStrings(n) << endl;

}
