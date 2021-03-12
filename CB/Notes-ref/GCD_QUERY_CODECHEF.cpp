/*
Constraints
Subtask #1: 40 points

2 ≤ T, N ≤ 100, 1 ≤ Q ≤ N, 1 ≤ A[i] ≤ 105
1 ≤ L, R ≤ N and L ≤ R
Subtask #2: 60 points

2 ≤ T, N ≤ 105, 1 ≤ Q ≤ N, 1 ≤ A[i] ≤ 105
1 ≤ L, R ≤ N and L ≤ R
Sum of N over all the test cases will be less than or equal to 106.

*/

/*

Input:
1
3 3
2 6 9
1 1
2 2
2 3

Output:
3
1
2


*/

#include<iostream>
using namespace std;
int gcd(int a, int b) {
	return (b == 0) ? a : gcd(b, a % b);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t; cin >> t;
	while (t--) {
		int n, q;
		cin >> n >> q;
		int a[100005];
		a[0] = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		// what I did earlier was that I repeated pre/suf for every query
		// which needs to computed only once and simply extract for each test case
		int pre[100005];
		int suf[100005];
		pre[0] = 0;
		suf[n + 1] = 0;
		for (int i = 1; i <= n; i++) {
			pre[i] = gcd(pre[i - 1], a[i]);
		}
		for (int i = n; i >= 1; i--) {
			suf[i] = gcd(suf[i + 1], a[i]);
		}
		while (q--) {
			int l, r;
			cin >> l >> r;
			cout << gcd(pre[l - 1], suf[r + 1]) << endl;
		}
	}
}
