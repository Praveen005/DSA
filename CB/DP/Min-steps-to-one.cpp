#include<iostream>
#include<climits>
using namespace std;
//MInimum steps to one
int minSteps_TopDown(int n, int dp[]) {
	//Base case
	if (n == 1) {
		return 0;
	}

	//Recursive case


	//we also need to, look up if a particular state is already computed
	if (dp[n] != 0) {
		return dp[n];
	}

	//compute if dp[n] is not present
	int op1, op2, op3;
	//all the options are not available all the time,
	//ex: if the number id not divisible by 3 then op1 won't be available.

	op1 = op2 = op3 = INT_MAX;
	if (n % 3 == 0) {
		op1 = minSteps_TopDown(n / 3, dp) + 1;
	}
	if (n % 2 == 0) {
		op2 = minSteps_TopDown(n / 2, dp) + 1;
	}
	op3 = minSteps_TopDown(n - 1, dp) + 1;

	int ans = min(min(op1, op2), op3);
	return dp[n] = ans;
}


int minSteps_BotUp(int n) {

	int dp[100] = {0};

	for (int i = 2; i <= n; i++) {
		int op1, op2, op3;
		op1 = op2 = op3 = INT_MAX;
		if (i % 3 == 0) {
			op1 = dp[i / 3]; //since we are computing bottom up, so dp[i/3], dp[i/2], dp[i-1] would already be computed
		}
		if (i % 2 == 0) {
			op2 = dp[i / 2];
		}
		op3 = dp[i - 1];
		dp[i] = min(op1, min(op2, op3)) + 1;
	}
	return dp[n];
}
int main() {

	int n;
	cin >> n;
	int dp[100] = {0};
	cout << minSteps_TopDown(n, dp) << endl;
	cout << minSteps_BotUp(n) << endl;
}
