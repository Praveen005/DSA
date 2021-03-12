
#include<iostream>
using namespace std;
int main() {

	int i = 0;
	int j = 0;
	int k = 0;
	int n;
	cin >> n;
	int a[n], b[n];
	int c[2 * n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	while (i < n && j < n) {
		if (a[i] < b[j]) {
			c[k] = a[i];
			i++;
		}
		else
		{
			c[k] = b[j];
			j++;
		}
		k++;
	}
	while (i < n) {
		c[k] = a[i];
		k++;
		i++;
	}
	while (j < n) {
		c[k] = b[j];
		k++;
		j++;
	}
	if (2 * n % 2 == 0) {
		cout << c[((2 * n / 2) + (2 * n / 2 + 1)) / 2 - 1];
	}
	else {
		cout << c[((2 * n + 1) / 2) - 1] << endl;

	}
}