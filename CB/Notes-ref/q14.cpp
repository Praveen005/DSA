//palindrome

//single element string is always palindromic
#include<iostream>
using namespace std;
bool palindrome(char a[] , int n) {
	int i = 0;
	int j = n - 1;
	while (i < j) {
		if (a[i] != a[j]) {
			return false;
		}
		i++;
		j--;
	}
	return true;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	char a[n];
	cin.get();
	for (int i = 0; i < n; i++) {
		cin >> a[i];

	}
	if (palindrome(a, n) == true) {
		cout << "true";
	}
	else {
		cout << "false";
	}



}
