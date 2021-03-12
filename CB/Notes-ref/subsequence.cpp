/*
	Print all sub sequences of a given string of characters.

	ex: for "abc" : {" ", "a", "b", "c", "ab", "ac", "bc", "abc"}

*/
#include<iostream>
#include<cstring>
using namespace std;
void generate_Subsequence(char *in, char* out, int i, int j) {
	//BASE CASE
	if (in[i] == '\0') {
		out[j] = '\0';
		cout << out << endl;
		return;
	}

	out[j] = in[i];
	// RECURSIVE CASE
	// include the character
	generate_Subsequence(in, out, i + 1, j + 1);

	//exclude the last character
	generate_Subsequence(in, out, i + 1, j);

}
int main() {
/*
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
*/

	char ch[] = "abcd";
	int i = 0, j = 0;
	char output[100];
	generate_Subsequence(ch, output, i, j);
}
