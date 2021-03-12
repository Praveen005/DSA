//printing all subsets(not only sub-strings) of a string using bitmasking
// sub-strings are contigous  while subsets might not be.
#include<iostream>
#include<cstring>
using namespace std;
void charFilter(char a[] , int n) {
	int j = 0;
	while (n > 0) {
		int last_character = (n & 1);
		if (last_character) {
			cout << a[j];
		}
		j++;
		n = (n >> 1);
	}
	cout << endl;
}

void printSubsets(char *a) {
	int n = strlen(a);
	for (int i = 0; i < (1 << n); i++) {
		charFilter(a, i);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w", stdout);
#endif
	char ch[ 100];
	cin >> ch;
	printSubsets(ch);
}