//revision of * factorial of large number*
#include<iostream>
using namespace std;
#define MAX 10000
int multiply(int res[], int i, int res_size) {
	int product;
	int carry = 0;
	int update;
	for (int j = 0; j < res_size; j++) {
		product = res[j] * i + carry;
		update = product % 10;
		res[j] = update;

		carry = product / 10;
	}
	while (carry) {
		res[res_size] = carry % 10;
		res_size++;
		carry = carry / 10;
	}
	return res_size;
}
void factorial(int n) {
	int res[MAX];
	res[0] = 1;
	int res_size = 1;
	for (int i = 2; i <= n; i++) {
		res_size = multiply (res, i, res_size);
	}
//	cout << "res_size = " << res_size << endl;
	for (int i = res_size - 1; i >= 0; i--) {
		cout << res[i];
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	factorial(n);
}