/*
You press some number on the keypad of your smartphone , ex-2,3

you've to generate all possible strings from them.

	2- "ABC"
	3- "DEF"


	possible strings:{ AD,AE,AF
					   BD,BE,BF
					   CD,CE,CF } , TOTAL:9
*/
#include<iostream>
#include<cstring>
using namespace std;
char keypad[][100] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};
void generate_string(char input[], char* out, int i, int j) {
	if (input[i] == '\0') {
		out[j] = '\0';
		cout << out << endl;
		return;
	}
	int digit = input[i] - '0';
	if (digit == 1 || digit == 0) {
		generate_string(input, out, i + 1, j);
	}
	for (int k = 0; keypad[digit][k] != '\0'; k++) {
		out[j] = keypad[digit][k];
		generate_string(input, out, i + 1, j + 1);
	}
	return;
}
int main() {
/*
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
*/
	char input[1000];
	cin >> input;
	char out[1000];
	int i = 0;
	int j = 0;
	generate_string( input,  out, i, j);

}
