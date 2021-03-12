//revision string tokenizer
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	char ch[] = "Today is a rainy day";

	// char* ptr = strtok(char * ch ,string delimiter)
	char* ptr = strtok(ch, " ");
	cout << ptr << endl;
	while (ptr != NULL) {
		ptr = strtok(NULL , " ");
		cout << ptr << endl;
	}

}
