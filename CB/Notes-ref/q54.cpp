//codechef  problem code : LONGPALI
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
bool palindrome(string s , int n) {
	int i = 0;
	int j = n - 1;
	while (i < j) {
		if (s[i] != s[j]) {
			return false;
		}
		i++;
		j--;
	}
	return true;
}
void subString(string s , int n) {
	char ch[5009];
	int maxm = 0;
	int count = 0;
	int len;
	string sm;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= n - i; j++) {
			string sub = s.substr(i , j);
			//cout << sub << endl;
			if (palindrome(sub , j)) {
				len = sub.length();
				if (maxm < len) {
					maxm = len;
					sm = sub;
				}
			}
		}
	}
	cout << maxm << endl;
	cout << sm << endl;
	return;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	string s;
	cin >> s;
	subString(s , n);

}