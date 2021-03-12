#include<iostream>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	string s;
	getline(cin, s);
	int n = s.length();
	int i;
	for (i = 0; i < n - 1; i++) {
		cout << s[i];
		cout << s[i + 1] - s[i];
		//cout << s[i + 1];
	}
	cout << s[i];
}