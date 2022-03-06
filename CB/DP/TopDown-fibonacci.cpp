#include<iostream>
using namespace std;
int fib(int n, int dp[]) {
	//Base case
	if (n == 0 || n == 1) {
		return n;
	}

	//recursive
	//check if the dp of the number has already been calculated
	if (dp[n] != 0) {
		return dp[n];
	}

	int ans;
	ans = fib(n - 1, dp) + fib(n - 2, dp);
	return dp[n] = ans;
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
	int dp[100] = {0};
	cout << fib(n, dp) << endl;
	return 0;
}
