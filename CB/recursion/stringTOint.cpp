/*

	INPUT: "1234" (STRING)
	
	OUTPUT: 1234 (INTEGER)

*/



#include<iostream>
#include<cstring>
using namespace std;
int stringTOinteger(char* ch, int n) {
	if (n < 0) {
		return 0;
	}

	int number = stringTOinteger(ch, n - 1);
	int digit = ch[n] - '0';
	return number * 10 + digit;

}
int main() {
	/*
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
*/

	char ch[25];
	cin.getline(ch, 25);
	int n = strlen(ch);
	int num = 0;
	cout << stringTOinteger(ch,  n - 1);
}
