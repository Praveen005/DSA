#include<iostream>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		string s1;
		cin >> s1;
		//getline(cin, s1);
		string s2;
		cin >> s2;
		//getline(cin, s2,);


		int n = s1.length();
		for (int i = 0; i < n; i++) {
			if (s1[i] != s2[i]) {
				cout << 1;
			}
			else {
				cout << 0;
			}
		}
		cout << endl;
	}
}