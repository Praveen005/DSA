#include<iostream>
#include<algorithm>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int t;
	cin >> t;
	//n is the size of the array
	while (t--) {
		int a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		next_permutation(a, a + n);
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
		cout << endl;

	}


}