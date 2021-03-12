#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
bool compare(string a, string b) {
	return a.length() < b.length();
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	string s[100];
	for (int i = 0; i < n; i++) {
		getline(cin, s[i]);
	}

	sort(s, s + n , compare);

	for (int i = 0; i < n; i++) {
		cout << s[i] << endl;
	}


}