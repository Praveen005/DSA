#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
#define ll long long
void solve(int *a, int* out, int n, int target, int i, int j, int sum , set<ll>&s) {

	if (sum == target) {
		sort(out, out + j );

		for (int k = 0; k < j ; k++) {
			cout << out[k] << " ";
		}
		cout << endl;

		sum = 0;

	}
	if (i == n ) {
		return;
	}
	if (sum + a[i] <= target) {
		sum += a[i];

		out[j] = a[i] ;

		solve(a, out, n, target, i + 1, j + 1, sum, s);
		sum -= a[i];
		solve(a, out, n, target, i + 1, j, sum, s);

	}
	else
		solve(a, out, n, target, i + 1, j, sum, s);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; cin >> n;
	int a[100];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int target; cin >> target;

	int output[100];
	set<ll>s;
	solve(a, output, n, target, 0, 0, 0, s);

	ll s1;
	// for (auto x : s) {
	// 	s1 = x;
	// 	for (int i = 0; s1[i] != '\0'; i++) {
	// 		cout << s1[i] << " ";
	// 	}
	// 	cout << endl;
	// }
	string s = 123;
	cout << s << endl;

}



