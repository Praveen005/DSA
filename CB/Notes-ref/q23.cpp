//string compression
#include<iostream>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	string s;
	cin >> s;
	int n = s.length();
	char ch;

	ch = s[0];
	cout << ch;
	int count = 1;
	for (int i = 1; i < n; i++) {
		if (s[i] == s[i - 1]) {
			count++;
		}
		else if (s[i] != s[i - 1]) {
			cout << count;
			ch = s[i];
			cout << ch;
			count = 1;

		}

	}
	cout << count;
}