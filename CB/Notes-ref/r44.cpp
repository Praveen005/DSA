// similar to sine series bus n! ke jagah n hai iss series me
// end term ka question

#include<iostream>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t; cin >> t; // t means no of terms;
	float x; cin >> x;
	float prod = (x * x * 1.0);

	double sum = 0.0;
	double term = x;

	for (int i = 1; i <= t; i++) {
		int p = (2 * i - 1);
		if (i % 2) {
			sum += (term / p);
		}
		else {
			sum -= (term / p);
		}
		term *= prod;

	}
	cout << sum << endl;
}