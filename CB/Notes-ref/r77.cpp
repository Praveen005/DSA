#include<iostream>
using namespace std;

int solve(int a[], int i, int j) {
	if (i > j) {
		return 0;
	}
	int sum1 = a[i] + min(solve(a, i + 1, j - 1), solve(a, i + 2, j));
	int sum2 = a[j] + min(solve(a, i, j - 2), solve(a, i + 1, j - 1));
	return max(sum1, sum2);



}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n; cin >> n;
	int a[40];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << solve(a, 0, n - 1);

	return 0;
}