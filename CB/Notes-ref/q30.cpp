#include<iostream>
#include<cctype>
using namespace std;
void type(char ch) {
	if (isupper(ch)) {
		cout << 'U';
	}
	else if (islower(ch)) {
		cout << "L";
	}
	else {
		cout << "I";
	}
}
int main() {
	char s;
	cin >> s;
	type(s);
}