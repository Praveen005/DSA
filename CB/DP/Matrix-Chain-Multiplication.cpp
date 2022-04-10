#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
using namespace std;
int solution(vector<int> &v) {
	//DP matrix will contain the min cost of multiplying matrices from l to r (l<=r)
	int dp[200][200];
	memset(dp, 0, sizeof(dp));


	int n = v.size() - 1; // total number of matrices to be multiplied

	//do remember that the dp[x][y] is to be filled diagonally

	//how many diagonals are to be filled? (ans: n)
	//Principle diagonal is already zero, so no need to worry about it
	for (int i = 1; i < n; i++) {
		//row from which I'm starting. we'll move diagonally
		int r = 0, c = i;
		while (c < n) {
			int val = INT_MAX;
			for (int pivot = r; pivot < c; pivot++) {
				val = min(val, dp[r][pivot] + dp[pivot + 1][c] + v[r] * v[pivot + 1] * v[c + 1]);
			}
			dp[r][c] = val;
			r++, c++;
		}
	}
	return dp[0][n - 1];
}
int main() {
/*
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
*/
	//Matrix Chain Multiplication

	vector<int> v{4, 2, 3, 1, 3};
	// vector<int>v{10, 20, 30} ;
	cout << solution(v) << endl;

}
