/*
Problem Statement:

https://hack.codingblocks.com/app/contests/1338/546/problem

*/
#include<iostream>
using namespace std;
const int N = 100000;

int SolveCellProblem(int n, int x, int y, int z) {
	//we will use the bottom up approach
	int dp[N] = {0};
	for (int i = 2; i <= n; i++) {
		//there are two cases

		if (i % 2 == 0) {
			dp[i] = min(dp[i / 2] + x, dp[i - 1] + y);

		}

		else {
			dp[i] = min(dp[i - 1] + y, dp[(i + 1) / 2] + x + z);
		}
	}
	return dp[n];
}
int main() {

	int n, x, y, z;
	cin >> n >> x >> y >> z;
	cout << SolveCellProblem(n, x, y, z) << endl;
}


/*
	cost Break-up;

	Double:  x
	+1    :  y
	-1    :  z

*/
