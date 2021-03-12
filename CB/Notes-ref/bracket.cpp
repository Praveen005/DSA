/*
	Generate balanced brackets using n-pairs of round brackets.

	ex: n=2,  { (())
					()() }

*/
#include<iostream>
#include<cstring>
using namespace std;
void generate_brackets(char * output, int n, int idx, int open, int close) {
	//BASE CASE
	if (idx == 2 * n) {
		output[idx] = '\0';
		cout << output << endl;
		return;
	}
	// recursive case
	if (open < n) {
		output[idx] = '(';
		// open++;
		generate_brackets(output, n, idx + 1, open + 1, close);
	}
	if (close < open) {
		output[idx] = ')';
		// close++;
		generate_brackets(output, n, idx + 1, open, close + 1);
	}
	// return;
}
int main() {
/*

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

*/
	int n; cin >> n;
	int idx = 0;
	int open = 0, close = 0;
	char output[1000];
	generate_brackets(output, n, idx, open, close);
}


