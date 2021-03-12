
#include <iostream>
#include<algorithm>
using namespace std;
bool compare(string s1 , string s2) {
	if (s2.find(s1) == 0) {
		return s2.length() > s1.length();

	}
	else if (s1.find(s2) == 0) {
		return s2.length() < s1. length();
	}
	else
	{
		return s1 < s2;
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w", stdout);
#endif
	int n;
	cin >> n;
	string s[1005];
	cin.get();
	for (int i = 0; i < n; i++) {
		getline(cin, s[i]);
	}
	sort(s, s + n, compare);
	for (int i = 0; i < n; i++) {
		cout << s[i] << endl;
	}
}
