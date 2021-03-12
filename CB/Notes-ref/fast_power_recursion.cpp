// calculating power(a,b) i.e.   a^b   using two meathods

#include<iostream>
using namespace std;
//niave approach
int power(int a, int n) {
	if (n == 0) {
		return 1;
	}
	return a * power(a, n - 1);
}
// O(log N)
int fast_power(int a, int n) {
	if (n == 0) {
		return 1;
	}
	int smaller_ans = fast_power(a, n / 2);
	smaller_ans *= smaller_ans;
	if (n & 1) {
		smaller_ans = a * smaller_ans;
	}
	return smaller_ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a, n;
	cin >> a >> n;
	cout <<   power(a, n) << endl;
	cout << fast_power(a, n) << endl;
}