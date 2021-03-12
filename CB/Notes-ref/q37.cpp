#include<iostream>
#include<algorithm>
using namespace std;
int main() {


	int a[] = {1, 2, 3, 4, 5, 5, 5};
	int n = sizeof(a) / sizeof(a[0]);

	sort(a, a + n);

	for (int i = 1; i < n; i++) {
		if (a[i] == a[i - 1]  || (a[i] < a[i - 1])) {
			a[i] = a[i - 1] + 1;
		}

	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}