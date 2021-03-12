//designing string tokenizer ** revision
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
char* mystrtok(char* str, char delim) {
	static char* input = NULL;
	if (str != NULL) {
		input = str;
	}
	if (input == NULL) {
		return NULL;
	}
	char* output = new char [strlen(input) + 1]; // dynamic memory allocation
	int i = 0;
	for ( ; input[i] != '\0'; i++) {
		if (input[i] != delim) {
			output[i] = input[i];
		}
		else {
			output[i] = '\0';
			input = input + i + 1;
			return output;
		}
	}
	output[i] = '\0';
	input = NULL;
	return output;

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	char ch[] = "Today is a very hot and sunny day";

	// char* ptr = strtok(char * ch ,string delimiter)
	char* ptr = mystrtok(ch, ' ');
	cout << ptr << endl;
	while (ptr != NULL) {
		ptr = mystrtok(NULL , ' ');
		cout << ptr << endl;
	}

}
