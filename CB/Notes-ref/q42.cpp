#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n ; i++) {
		int j = i; int num = n;
		int num1 = ((2 * n + 1) - (2 * i));
		while (j--) {
			cout << num << " ";
			num--;
		}
		num++; j += 2;
		while ( num1 > 0) {
			cout << "  ";
			num1--;
		}
		while (j <= i) {

			cout << num << " ";
			num++;
			j++;

		}
		cout << endl;
	}
	int k = n;
	while (k >= 0) {
		cout << k << " ";
		k--;
	}
	k = n; int i = 1;
	while (k > 0) {
		cout << i << " ";
		i++;
		k--;
	}

	cout << endl;


	for (int i = 1; i <= n ; i++) {
		int n1 = n - i + 1; k = n;
		while (n1--) {
			cout << k << " ";
			k--;
		}

		int j = (2 * i - 1);
		while (j--) {
			cout << "  ";
		}

		int l = i;
		k = i;
		while (l <= n) {
			cout << k << " ";
			k++;
			l++;
		}

		cout << endl;
	}
}