#include<iostream>
using namespace std;
int fib(int n) {
base case
		if (n == 0 || n == 1) {
			return  n;
		}
	//recursive case
	return fib(n - 1) + fib(n - 2);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	cout << fib(n) << endl;
}