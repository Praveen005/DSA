#include<iostream>
#include<cstring>
using namespace std;
bool palindrome(char* ch) {
	int n = strlen(ch);
	if (n == 1) {
		return true;
	}
	int l = 0, r = n - 1;
	while (l < r) {
		if (ch[l] != ch[r]) {
			return false;
		}
		l++;
		r--;
	}
	return true;
}
int s2i(char* ch) {
	int n = strlen(ch);
	int ans = 0;
	int fact = 1;
	for (int i = n - 1; i >= 0; i--) {
		ans += ((ch[i] - '0') * fact);
		fact *= 10;
	}
	return ans;
}

bool palin(int a) {
	int num = a;
	int ans = 0;
	int fact = 1;
	while (a > 0) {
		int k = a % 10;
		ans = (ans * 10) + k;
		a = a / 10;
	}
	if (ans == num) {
		return true;
	}
	return false;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// char ch[10000];
	// cin >> ch;
	// if (palindrome(ch)) {
	// 	cout << "yes" << endl;
	// }
	// else {
	// 	cout << "no" << endl;
	// }
	// cout << ch + 1 << endl;
	// cout << s2i(ch) << endl;

	int n; cin >> n;

	if (palin(n)) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
	for (int i = n + 1; i < n + 2000; i++) {
		if (palin(i)) {
			cout << i << endl;
		}
	}
}