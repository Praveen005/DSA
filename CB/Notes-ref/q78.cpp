//rotation of string

#include<iostream>
#include<cstring>
using namespace std;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);

	freopen("output.txt" , "w", stdout);
#endif

	char ch [100] = "prateek";

	int n = strlen(ch);
	int k; cin >> k;
	for (int i = n - 1; i >= 0; i-- ) {
		ch[i + k] = ch[i];


	}
	for (int i = 0; i < k; i++ ) {
		ch[i] = ch[n - 2 + k + i];


	}
	ch[n] = '\0';
	cout << ch << endl;


}