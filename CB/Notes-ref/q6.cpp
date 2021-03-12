//string palindrom
#include<iostream>
#include<cstring>
using namespace std;
bool palindrome(char ch[]) {
	int j = strlen(ch) - 1;
	int i = 0;
	while (i < j) {
		if (ch[i] != ch[j]) {
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


	char ch[100];
	cin >> ch;
	if (palindrome(ch) == true) {
		cout << "yes" << endl;
	}
	else {
		cout << "no";
	}


}