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

	char ch[10000];
	int maxm = 0;
	int count;
	int len;
	char sm[5009];
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			len = 0;
			count = 0;
			for (int k = i; k <= j; k++) {

				ch[count] = s[k];
				count++;

			}
			ch[count] = '\0';

			if (palindrome((string)ch , count)) {

				len = strlen(ch);

				if (maxm < len) {
					maxm = len;
					strcpy(sm, ch);
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
// 1≤N≤5000.
// You may assume that in 30% of the inputs 1≤N≤300.
// Sample Input 1: