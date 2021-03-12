#include<iostream>
#include<cstring>
using namespace std;
int main() {
	string s;
	cin >> s;
	int l = 0;
	int count = 0;
	for (int i = 0; i < s.length(); i++) {
		if (isupper(s[i])) {
			count++;
		}
		if (count == 2) {
			count = 0;
			i--;
			cout << endl;
			continue;
		}
		if (islower(s[i])) {
			cout << s[i];
		}
		else {
			cout << s[i];
		}
	}
}