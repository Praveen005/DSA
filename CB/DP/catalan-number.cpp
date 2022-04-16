#include<iostream>
using namespace std;
#define ll long long
ll CatalanNumber(int n, ll dp[]) {
	//Base case
	if (n == 0 || n == 1) {
		return 1;
	}

	//check if already calculated
	if (dp[n]) {
		return dp[n];
	}
	for (int i = 1; i <= n; i++) {
		dp[n] += (ll)CatalanNumber(i - 1, dp) * CatalanNumber(n - i, dp);
	}

	return dp[n];
}
int main() {

	int n; cin >> n;
	ll dp[100] = {0};
	cout << CatalanNumber( n, dp) << endl;
}
