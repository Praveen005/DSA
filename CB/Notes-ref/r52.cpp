#include<iostream>
#include<climits>
using namespace std;
int inversionCount(int a[], int n) {

}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n; cin >> n;
	int arr[n] = {0};
	int m; cin >> m;
	int a, b, k;
	int sum = INT_MIN;

	while (m--) {
		cin >> a >> b >> k;
		for (int i = a; i <= b; i++) {
			arr[i] += k;
			sum = max(sum, arr[i]);
		}
	}
	cout << sum << endl;
}