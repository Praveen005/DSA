/*
	given: 1-A
		   2-B
		   3-C      GIVEN ARRAY: {1,2,3,4} ;we have to generate string using this array.
		   ...
		   26-Z

		   OUTPUT:  1,2,3,4-ABCD
		   			12,3,4-LCD
		   			1,23,4-AWD
		   			1,2,34 - NOT POSSIBLE  since 34>26

*/

#include<iostream>
using namespace std;


void string_generation(char* in, char* out,  int i, int j) {
	if (in[i] == '\0') {
		out[j] = '\0';
		cout << out << endl;
		return;
	}
	int digit = in[i] - '0';
	if (digit != 0) {
		char ch = digit + 'A' - 1;
		out[j] = ch;
		string_generation(in, out, i + 1, j + 1);
	}
	if (in[i + 1] != '\0') {
		int digit2 = digit * 10 + (in[i + 1] - '0');
		if (digit2 <= 26) {
			char ch = digit2 + 'A' - 1;
			out[j] = ch;
			string_generation(in, out, i + 2, j + 1);
		}
	}
	return;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	char a[1000];
	cin >> a;
	int i = 0, j = 0;
	char output[1000];
	string_generation(a, output, i, j);

}