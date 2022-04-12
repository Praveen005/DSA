//problem:    https://www.spoj.com/problems/MIXTURES/

#include<iostream>
#include<climits>
using namespace std;
int a[1000];
long long dp[1000][1000];

long long sum(int i, int k) {
	long long ans = 0;
	for (int j = i; j <= k; j++) {
		ans += a[j];
		ans %= 100;
	}
	return ans;
}
long long SolveMixtures(int i, int j) {
	// base case
	if (i >= j) {
		return 0;
	}

	//If the answer is already computed
	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	//We break our expression at every possible k
	dp[i][j] = INT_MAX;

	for (int k = i; k < j; k++) {
		dp[i][j] = min(dp[i][j], SolveMixtures(i, k) + SolveMixtures(k + 1, j) + sum(i, k) * sum(k + 1, j));
	}
	return dp[i][j];
}

int main() {


	// int n;
	// int colors[101];

	/*
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			cin >> colors[i];
		}

		for (int i = 0; i < n; i++) {
			cout << colors[i] << " ";
		}
		cout << endl;

	}
	*/

	int n;
	while (scanf( "%d", &n) != EOF) {   //EOF: end of file
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}


		//Initializing the Dp[] with -1

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dp[i][j] = -1;
			}
		}
		cout << SolveMixtures(0, n - 1) << endl;
	}
}
