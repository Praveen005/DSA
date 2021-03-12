#include<iostream>
using namespace std;
void charType(int a) {
	if (a >= 65 && a <= 90) {
		cout << "UPPERCASE";
	}
	else if (a >= 97 && a <= 122) {
		cout << "lowercase";
	}
	else {
		cout << "Invalid";
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	char ch;
	cin >> ch;
	charType(ch);
}